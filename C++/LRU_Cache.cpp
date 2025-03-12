#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


class LRUCache {
    private:
        int capacity;
        
        list <pair<int, int>> items;

        unordered_map<int, list<pair<int, int>>::iterator> cache;

    public:
        LRUCache(int capacity)
        {
            this -> capacity = capacity;
        }

        int get(int key)
        {
            if(cache.find(key) == cache.end())
            {
                return -1;
            }

            items.splice(items.begin(), items, cache[key]);
            return cache[key]->second;
        }

        void put(int key, int value)
        {
            if(cache.find(key) != cache.end())
            {
                cache[key]->second = value;
                items.splice(items.begin(), items, cache[key]);
                return;
            }

            if(items.size() == capacity)
            {
                int keyToRemove = items.back().first;
                items.pop_back();
                cache.erase(keyToRemove);
            }

            items.push_front({key, value});
            cache[key] = items.begin();
        }
};

int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl;

    cache.put(3, 3);
}


