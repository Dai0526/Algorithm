/*
Idea: Use a data structure to track which vector needs to be checked. 

Cyclic properties: ----> Queue

*/
#include <vector>

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        
        if(v1.begin() != v1.end()){
            iterQueue.push(v1.begin());
            endIterQueue.push(v1.end());
        }
        
        if(v2.begin() != v2.end()){
            iterQueue.push(v2.begin());
            endIterQueue.push(v2.end());
        }

    }

    int next() {
        vector<int>::iterator curr = iterQueue.front();
        vector<int>::iterator end = endIterQueue.front();
        
        iterQueue.pop();
        endIterQueue.pop();
        
        int n = *curr;
   
        ++curr;
        
        if(curr != end){
            iterQueue.push(curr);
            endIterQueue.push(end);
        }
        
        return n;
    }

    bool hasNext() {
        return iterQueue.size() > 0;
    }
    
private:
    
    queue<vector<int>::iterator> iterQueue; 
    queue<vector<int>::iterator> endIterQueue;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */