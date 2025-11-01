#include <iostream>
#include <thread>
#include <mutex>
#include<atomic>
#include <vector>

std::mutex mtx;
using namespace std; 
int counter = 0;
atomic<bool> flag(false);
atomic<int> cnt(0);


bool tas(int thread_num)
{
  if(flag == false)
  {
    // mtx.lock();
    // cout << "Thread T" << thread_num << " got the lock" << endl;
    // mtx.unlock();
    flag = true; 
    return true;
  }
  else{ return false;}
}

void increment(int thread_num) {

  for(int i = 0; i < 3; i++)
  {

 
      while(tas(thread_num) == false);
       // Critical section
      // mtx.lock();
      // cout << "Thread T" << thread_num << " entered critical section\n";
      // // cout << "Thread T" << thread_num << " incremented counter to " << counter << endl;
      // cout << "Thread T"<< thread_num << " leaving the lock " << endl;
      // cout << endl;
     
      // mtx.unlock();
      counter ++;
      flag = false;
      
  }

}

// TAS
bool tas2()
{
  if(flag.load(std :: memory_order_relaxed) == false)
  {
    flag.store(true, std :: memory_order_seq_cst);
    return true;
  }
  return false;
}

// INC for TAS
void inc()
{
  // while(flag.load(std :: memory_order_relaxed) == false){;}
  for(int i = 0; i < 10; i++)
  {
    while(!tas2());
    cnt++;
    // mtx.lock();
    // cout << cnt << endl;
    // mtx.unlock();
    flag.store(false, std :: memory_order_seq_cst);
  }

}

// INC for TTAS
void inc2()
{
  for(int i = 0; i < 10; i++)
  {
    while(flag.load(std :: memory_order_relaxed) == true || (!tas2()));
    cnt++;
    // mtx.lock();
    // cout << cnt << endl;
    // mtx.unlock();
    flag.store(false, std :: memory_order_seq_cst);
  }
}


atomic<int> next_num(0); 
atomic<int> now_serving(0);
atomic<int> t_cnt(0);

void ticket_lock()
{
  int my_num = next_num.fetch_add(1, std :: memory_order_relaxed);
  while(my_num != now_serving.load(std :: memory_order_seq_cst)){;}
}

void ticket_unlock()
{
  now_serving.fetch_add(1, std :: memory_order_seq_cst);
}

void ticket_inc()
{
  for(int i = 0; i < 5; i++)
  {
    ticket_lock();
    t_cnt++;
    ticket_unlock();

    // t_cnt.compare_exchange_strong
  }
}
struct Node {
    std::atomic<Node*> next;
    std::atomic<bool> locked;
};

std::atomic<Node*> tail(nullptr);
atomic<int> mcs_cnt(0);

void mcs_lock(Node* myNode) {
    myNode->next.store(nullptr);
    myNode->locked.store(true);

    Node* oldTail = tail.exchange(myNode, std::memory_order_acq_rel);

    if (oldTail != nullptr) {
        oldTail->next.store(myNode);
        while (myNode->locked.load(std::memory_order_acquire))
            ; // spin
    }
}

void mcs_unlock(Node* myNode) {
    Node* succ = myNode->next.load();

    if (succ == nullptr) {
        Node* expected = myNode;
        if (tail.compare_exchange_strong(expected, nullptr))
            return;  // no one waiting
        // Wait until successor appears
        while ((succ = myNode->next.load()) == nullptr)
            ;
    }
    succ->locked.store(false, std::memory_order_release);
}


void mcs_inc()
{
  for(int i = 0; i < 5; i++)
  {
    
    mcs_cnt++;
  
  }
}


atomic<bool>desires[2];
atomic<int>turn; 
int array[2] = {0};
atomic<int>p_cnt(0);

void peterson_lock_init()
{
  desires[0].store(false, memory_order_seq_cst);
  desires[1].store(false, memory_order_seq_cst);
  turn.store(0, memory_order_seq_cst);
}

void peterson_lock(int tid)
{
  // change the desire of current thread
  desires[tid].store(true, memory_order_seq_cst);
  int other_tid = 0;
  if(tid == 0)
  {
    other_tid = 1;
  }
  else{
    other_tid = 0;
  }

  turn.store(other_tid, memory_order_seq_cst);

  while(desires[other_tid].load(memory_order_seq_cst) && turn.load(memory_order_seq_cst) == other_tid)
  {
  }

}

void peterson_unlock(int tid)
{
  desires[tid].store(false, memory_order_seq_cst);
}

void peterson_inc(int tid)
{
  for(int i = 0; i < 5; i++)
  {
    peterson_lock(tid);
    p_cnt++;
    peterson_unlock(tid);
    
  }
}

#define RELAXED std :: memory_order_relaxed
#define SEQCST std :: memory_order_seq_cst
void lock(atomic<bool> x){
    bool expected = false;
    bool desired = true;
    while(x.compare_exchange_strong(expected, desired, SEQCST) == false){;};
}

void unlock(atomic<bool> x)
{
    x.store(false, SEQCST);
}
int cnt = 0;
void inc3()
{
    atomic<bool> flag;
    lock(flag);
    cnt ++;
    unlock(flag);
}
int main() {

    vector<thread> threads; 

    // peterson's algo
    for(int i = 0; i<2; i++)
    {
      threads.emplace_back(peterson_inc, i);
    }

    for(auto &t : threads)
      t.join();

    std::cout << "Counter: " << p_cnt << std::endl;

}
