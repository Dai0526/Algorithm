/*
https://leetcode.com/problems/kth-missing-positive-number/
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr = 1;
        int idx = 0;
        int count = 0;
        
        while(count != k && idx < arr.size()){
            if(curr == arr[idx]){
                ++idx;
                ++curr;
                continue;
            }
            
            ++curr;
            ++count;
        }
        
        --curr;
        
        while(count < k){
            ++curr;
            ++count;
        }
        
        return curr;
    }
};