/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/
Find the min and max element in unsorted subarray
*/
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        
        stack<int> stk;
        int l = n;
        int r = 0;
        
        for(int i = 0; i < n; ++i){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        stack<int> stk2;
        for(int i = n - 1; i >=0; --i){
            while(!stk2.empty() && nums[stk2.top()] < nums[i]){
                r = max(r, stk2.top());
                stk2.pop();
            }
            stk2.push(i);
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
    
    int findUnsortedSubarray_nlogn(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        vector<int> sorted(nums);  
    
        sort(sorted.begin(), sorted.end());
    
        // find idx that has changed
        int l = n;
        int r = 1;
        for(int i = 0; i < n; ++i){
            if(sorted[i] != nums[i]){
                l = min(l, i);
                r = max(r, i);
            }
        }
        return r - l < 0 ? 0 : r - l + 1;
    }
    
    int findUnsortedSubarray_naive(vector<int>& nums) {
        
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        
        // find left idx and right idx that need to be sort
        int l = n;
        int r = 0;
        
        // selection sort
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(nums[j] < nums[i]){
                    r = max(r, j);
                    l = min(l, i);
                }
            }
        }
        
        return r - l < 0 ? 0 : r - l + 1;
    }
};