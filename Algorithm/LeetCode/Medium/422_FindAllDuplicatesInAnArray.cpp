/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/
1. Use a map, save count, and find that appear twice
    use extra space
2. sort, then compare with adjenct element
    time O(nLogn)
3. O(n) with no extra space
    Because the integer is  1<= x <= n
    We can mark according numbner to negative, then loop over to find the postive one

*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        
        for(int n : nums){
            nums[abs(n) - 1] *= -1;
        }
        
        for(int n : nums){
            if(nums[abs(n) - 1] > 0){
                ans.push_back(abs(n));
                nums[abs(n) - 1] *= -1;
            }
        }
        
        return ans;
    }

    vector<int> findDuplicates_space(vector<int>& nums) {
        map<int, int> numMap;
        
        vector<int> ans;
        
        for(int n : nums){
            ++numMap[n];
            if(numMap[n] == 2){
                ans.push_back(n);
            }
            
        }
        
        // or use another loop to find count == 2
        return ans;   
    }
};