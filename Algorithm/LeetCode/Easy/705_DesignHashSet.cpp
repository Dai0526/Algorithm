/*
https://leetcode.com/problems/design-hashset/
*/
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
private:
    
    const int bucketSize = 2000;
    vector<list<int>> vec;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        vec.resize(bucketSize, list<int>());
    }
    
    void add(int key) {
        int idx = getHash(key);
        
        bool exist = false;
        for(int n : vec[idx]){
            if(n == key){
                exist = true;
            }
        }
        
        if(!exist){
            vec[idx].push_back(key);
        }
        
    }
    
    void remove(int key) {
        int idx = getHash(key);
        vec[idx].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int idx = getHash(key);
        for(int n : vec[idx]){
            if(n == key){
                return true;
            }
        }
        
        return false;
    }

private:
    int getHash(int key){
        return key % bucketSize;         
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */