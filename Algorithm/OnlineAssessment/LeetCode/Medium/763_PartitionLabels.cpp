/*
https://leetcode.com/problems/partition-labels/
Find the first apperance and the last apperance of each characters, 
keep find the right boundry for each partition, then do partition.
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> rightBoundry(26, -1);
        
        for(int i = 0; i < S.length(); ++i){
            rightBoundry[S[i] - 'a'] = i;
        }
        
        vector<int> parts;
        
        int l = 0;
        int r = 0;
        
        for(int i = 0; i < S.length(); ++i){
            r = max(r, rightBoundry[S[i] - 'a']);
            
            if(i == r){
                parts.push_back(r - l + 1);
                l = i + 1;
                r = i + 1;
            }
        }
        
        return parts;
    }
};