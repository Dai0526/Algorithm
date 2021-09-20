#include <vector>
#include <list>

using namespace std;

class MyHashMap {

private:
    
    vector<vector<pair<int,int>>> map;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(100);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hash = getHash(key);
        
        for(pair<int,int>& p : map[hash]){
            if(p.first == key){
                // if already exist, then update value;
                p.second = value;
                return;
            }
        }
        
         map[hash].push_back({key, value});
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hash = getHash(key);
        for(pair<int,int>& p : map[hash]){
            if(p.first == key){
                // if already exist, then update value;
                return p.second;
            }
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hash = getHash(key);
        for(auto a = map[hash].begin(); a != map[hash].end(); ++a){
            if(a->first == key){
                map[hash].erase(a);
                return;
            }
        }
    }
    
    int getHash(const int key) const{
        return key % 100;
    }
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */