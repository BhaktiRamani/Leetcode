#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <memory>

using namespace std;

#define RELAXED std :: memory_order_relaxed
#define SEQCST std :: memory_order_seq_cst
#define REL std :: memory_order_release
#define ACQ std :: memory_order_acquire
#define ACQ_REL std :: memory_order_acq_rel


class counter{
    protected : 
        int cnt = 0; 
        

    public :
        virtual void lock()  = 0;
        virtual void unlock()  = 0;  
        virtual ~counter() = default;


        void inc()
        {
            lock(); 
            cnt++;
            unlock();
        }

        int get() const { return cnt; }
};


class tas{
    atomic<bool> flag{false};

    public :
        void lock(){
            bool expected = false;
            bool desired = true;
            while(flag.compare_exchange_strong(expected, desired, SEQCST) == false){;};
        }

        void unlock()
        {
            flag.store(false, SEQCST);
        }
};

class tasrel{
    atomic<bool> flag{false};

    public :
        void lock(){
            bool expected = false;
            bool desired = true;
            while(flag.compare_exchange_strong(expected, desired, ACQ_REL) == false){;};
        }

        void unlock()
        {
            flag.store(false, REL);
        }

};

class ttas{
    atomic<bool> flag{false};

    public :
        void lock(){
            bool expected = false;
            bool desired = true;
            while(flag.load(SEQCST) == true || flag.compare_exchange_strong(expected, desired, SEQCST) == false){;};
        }

        void unlock()
        {
            flag.store(false, SEQCST);
        }
};


class ttasrel{
    atomic<bool> flag{false};

    public :
        void lock(){
            bool expected = false;
            bool desired = true;
            while(flag.load(ACQ) == true || flag.compare_exchange_strong(expected, desired, ACQ_REL) == false){;};
        }

        void unlock()
        {
            flag.store(false, REL);
        }
};


class Ticket_Lock{
    std::atomic<int> next_num{0};
    std::atomic<int> now_serving{0};

    
    public : 
        void lock() 
        {
            int my_num = next_num.fetch_add(1, RELAXED);
            while(my_num != now_serving.load(SEQCST)){;}
        }

        void unlock()  
        {
            now_serving.fetch_add(1, SEQCST);
        }
};

class Pthread{
    mutex mtx;

    public : 
        void lock()
        {
            mtx.lock();
        }

        void unlock()
        {
            mtx.unlock();
        }
};

class Peterson {
    atomic<bool>desires[2];
    atomic<int>turn; 

    public : 

        void lock(int tid)
        {
            // change the desire of current thread
            desires[tid].store(true, SEQCST);
            int other_tid = 0;
            if(tid == 0)
            {
                other_tid = 1;
            }
            else{
                other_tid = 0;
            }

            turn.store(other_tid, SEQCST);

            while(desires[other_tid].load(SEQCST) && turn.load(SEQCST) == other_tid)
            {}

        }

        void unlock(int tid)
        {
             desires[tid].store(false, SEQCST);
        }
};

class Petersonrel {
    atomic<bool>desires[2];
    atomic<int>turn; 

    public : 

        void lock(int tid)
        {
            // change the desire of current thread
            desires[tid].store(true, REL);
            int other_tid = 0;
            if(tid == 0)
            {
                other_tid = 1;
            }
            else{
                other_tid = 0;
            }

            turn.store(other_tid, REL);
            // thread fence 
            while(desires[other_tid].load(ACQ) && turn.load(ACQ) == other_tid)
            {}
        }

        void unlock(int tid)
        {
             desires[tid].store(false, REL);
        }
};




class MCS_Node{
    public : 
        atomic<MCS_Node*>next{nullptr};
        atomic<bool> wait{false};
};

class MCSLock{
    atomic<MCS_Node*> tail{NULL}; 

    public : 
        void acquire(MCS_Node* myNode)
        {
            MCS_Node* oldTail = tail.load(SEQCST); 

            while (!tail.compare_exchange_strong(oldTail, myNode, SEQCST)) {
                oldTail = tail.load(SEQCST);
            }


            if(oldTail != NULL)
            {
                myNode -> wait.store(true, RELAXED);
                oldTail -> next.store(myNode, SEQCST);
                while(myNode -> wait.load(SEQCST)){;}
            }
        }


        void release(MCS_Node *myNode){
            MCS_Node *m = myNode;
            if(tail.compare_exchange_strong(m, NULL, SEQCST))
            {

            }
            else{
                while(myNode -> next.load(SEQCST) == NULL){}; 
                myNode -> next.load(SEQCST) -> wait.store(false, SEQCST);
            }
        }


};

class MCSLockrel{
    atomic<MCS_Node*> tail{NULL}; 

    public : 
        void acquire(MCS_Node* myNode)
        {
            MCS_Node* oldTail = tail.load(ACQ); 

            while (!tail.compare_exchange_strong(oldTail, myNode, ACQ_REL)) {
                oldTail = tail.load(ACQ);
            }


            if(oldTail != NULL)
            {
                myNode -> wait.store(true, RELAXED);
                oldTail -> next.store(myNode, REL);
                // fence
                while(myNode -> wait.load(ACQ)){;}
            }
        }


        void release(MCS_Node *myNode){
            MCS_Node *m = myNode;
            if(tail.compare_exchange_strong(m, NULL, ACQ_REL))
            {

            }
            else{
                while(myNode -> next.load(ACQ) == NULL){}; 
                myNode -> next.load(ACQ) -> wait.store(false, REL);
            }
        }


};

int main()
{

    std :: vector<std :: thread> threads; 
    const int NUM_THREADS = 8;
    const int INCREMENTS_PER_THREAD = 5;

    // ttasrel lock;
    MCSLockrel lock;
    int cnt = 0;

    for(int i = 0; i < NUM_THREADS; i++) 
    {    threads.emplace_back([&]()
         { MCS_Node myNode; 
        for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) 
        {   
            // lock.lock();
            lock.acquire(&myNode); 
            cnt++; 
            lock.release(&myNode); 
            // lock.unlock(); 
        }
    });
    }     
 
    // for (int i = 0; i < NUM_THREADS; ++i) {
    //     threads.emplace_back([&, i]() {
    //         MCS_Node myNode; // each thread has its own node

    //         for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
    //             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // to slow things down for clarity

    //             std::cout << "Thread " << i << " trying to acquire lock (iter " << j << ")\n";

    //             lock.acquire(&myNode);
    //             // lock.lock();
    //             std::cout << "Thread " << i << " acquired lock (iter " << j << ")\n";

    //             // critical section
    //             int local = cnt;
    //             std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    //             cnt = local + 1;

    //             std::cout << "Thread " << i << " incremented cnt to " << cnt << "\n";

    //             lock.release(&myNode);
    //             // lock.unlock();
    //             std::cout << "Thread " << i << " released lock (iter " << j << ")\n\n";
    //         }
    //     });
    // }

    for (auto &t : threads) {
        t.join();
    }
    cout << "cnt : " << cnt << endl;

    //  string str = "TICKET";

    //  counter *c = nullptr;

    //  if(str == "TICKET")
    //  {
    //     c = new Ticket_Lock();
    //  }

    // const int NUM_THREADS = 8;
    // const int INCREMENTS_PER_THREAD = 5;

    // std::vector<std::thread> threads;

    // // Spawn threads — each increments the shared counter
    // for (int i = 0; i < NUM_THREADS; ++i) {
    //     threads.emplace_back([&]() {
    //         for (int j = 0; j < INCREMENTS_PER_THREAD; ++j) {
    //             c->inc();
    //         }
    //     });
    // }

    // // Wait for all threads to finish
    // for (auto& t : threads) t.join();

    // std::cout << "Final count = " << c->get() << "\n";
    // std::cout << "Expected = " << NUM_THREADS * INCREMENTS_PER_THREAD << "\n";

    // delete c;
    return 0;
}