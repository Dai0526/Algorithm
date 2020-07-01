#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> records;
        
        for(string& str : words){
            ++records[str]; 
        }
        
        auto comp = [](pair<string, int>& x, pair<string, int>& y){
            if(x.second != y.second){
                return x.second > y.second;
            }  
            return x.first.compare(y.first) < 0;
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
        
        // iterate map and add to pq
        for(pair<string,int> p : records){
            pq.push(p);
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<string> out;
        while(!pq.empty()){
            out.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(out.begin(), out.end());
        return out;
    }


};