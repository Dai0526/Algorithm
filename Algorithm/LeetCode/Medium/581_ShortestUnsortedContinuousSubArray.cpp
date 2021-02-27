/*
    https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
    
    3 solutions
    1. sorting
    2. two ptrs to find left and right - idea of selection sort
    3. stack
*/
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int findUnsortedSubarray_srot(vector<int>& nums) {
        
    vector<int> temp(nums);
        
    sort(temp.begin(), temp.end());
        
    int r = 0;
    int l = temp.size() - 1;
        
        //[2,6,4,8,10,9,15]
        //[2,4,6,8,9,10,15]
    for(int i = 0; i < temp.size(); ++i){
        if(nums[i] != temp[i]){
            r = max(i, r);
            l = min(i, l);
        }
    }
    
    if(l - r >= 0){
        return 0;
    }
        
    return r - l + 1;
}

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
    