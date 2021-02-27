/*
https://leetcode.com/problems/find-the-most-competitive-subsequence/

Idea:

Target: maintain the min subsequence with fixed size

for each number n in nums:
    1. check stack top
        if top > n:
            stack pop unitl 1. there is enough number in nums to make a k-sized stack. && 2. top greater than n
    2. push curr if stack size < k

*/
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        if(nums.size() == k){
            vector<int> ans(nums);
            return ans;
        }
        
        
        vector<int> seq; // vector as stack
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            
            int curr = nums[i];
            
            while(!seq.empty() && seq.back() > curr && hasEnoughCandidateAfterPop(i, k, seq.size(), n)){
                seq.pop_back();
            }
            
            if(seq.size() < k){
                seq.push_back(curr);
            }
        }
        
        return seq;
    }
               
    bool hasEnoughCandidateAfterPop(int idx, int k, int nSeq, int nNum){
        int nRemain = k - (nSeq - 1); // after pop
        int nLeft = nNum - idx;
        if(nRemain <= nLeft){
            return true;
        }
        
        return false;
    }
};