/*
https://leetcode.com/problems/sort-characters-by-frequency/
Several ideas
1. bucket sort by its frequency
2. customer comparator for a max heap
3. customer comparator to sort an array
*/

#include <queue>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> counts;
        priority_queue<pair<int, char>> pq;
        
        for(char c : s){
            ++counts[c];
        }
        
        for(unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); ++it){            
            pq.push({it->second, it->first});
        }
        
        stringstream ss;
        int size = pq.size();

        for(int i = 0; i < size; ++i){
            int n = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            ss << string(n, c);
        }        
        
        return ss.str();
    }
};