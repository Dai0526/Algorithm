/*
https://leetcode.com/problems/find-the-duplicate-number/

Several workablt solution:
1. Sort then iteration
2. Use a Set/map to record 
3. turn it into find intersection problem. * better time, and better space
    a. take input vector as a new vector, idx is previous number,
        e.g. 1 3 5 2 0 4 -> 3 2 5 4 0 1
    b. thus, if one number occur multiple times, there will be a cycle
    c. 2 ptr chasing find a point with cycle
    d. 2 ptr find entry of the cycle, which is the targeting number

4. indexing mark as negative number

*/
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        for(int i = 0; i < nums.size(); ++i){
            int idx = abs(nums[i]) - 1;
            
            nums[idx] *= -1;
            if(nums[idx] > 0){
                // already visited, which is duplicated case
                return abs(nums[i]);
            }
            
        }
        
        return -1;
    }
    
    int findDuplicate_cycle(vector<int>& nums) {
        int n = nums.size();
        
        int slow = nums[0];
        int fast = nums[0];
        // detect cycle
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        // find entry of cycl
        fast = nums[0];
        
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
    }
};