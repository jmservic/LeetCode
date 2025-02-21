#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    private:
        unordered_map<int, pair<int, list<int>::iterator>> cache;
        list<int> LRUList;
        int capacity;
        int LRUKey;
    public:
        LRUCache(int capacity) : capacity(capacity) {
            
        }
        
        int get(int key) {
            auto it = cache.find(key);
            if(it != cache.end())
            {
                updateLRUList(key);
                return it->second.first;
            }                
            else
                return -1;
        }
        
        void put(int key, int value) {
            if (!cache.contains(key))
            {
                if(cache.size() < capacity)
                {
                    cache[key] = {value, LRUList.end()};
                } else {
                    cache.erase(LRUList.back());
                    LRUList.pop_back();
                    cache[key] = {value, LRUList.end()};
                }                
            } else
                cache[key].first = value;

            updateLRUList(key);
        }

        void updateLRUList(int key)
        {
            auto it = cache[key].second;
            if(it != LRUList.end())
            {
                LRUList.splice(LRUList.begin(), LRUList, it);
            } else 
            {
                LRUList.push_front(key);
            }

            cache[key].second = LRUList.begin();
            
        }
};