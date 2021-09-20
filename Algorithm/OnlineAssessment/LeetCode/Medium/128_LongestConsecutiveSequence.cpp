/*
nLogn solution will be sort then iterating
Thus,
Union Find Idea
https://leetcode.com/problems/longest-consecutive-sequence/
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numSet(nums.begin(), nums.end());

        int lcLen = 0;
        
        int* pNums = nums.data();
        
        for(int i = 0; i < nums.size(); ++i){
            int n = pNums[i];
            if(numSet.find(n - 1) != numSet.end()){
                continue; // skip if already done
            }
            
            int curr = n + 1;
            
            while(numSet.find(curr) != numSet.end()){
                ++curr;
            }
            
            lcLen = max(lcLen, curr - n);    
        }
                
        return lcLen;
        
    }
};