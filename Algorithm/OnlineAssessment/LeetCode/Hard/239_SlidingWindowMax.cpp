/*
https://leetcode.com/problems/sliding-window-maximum/
1. maintain a decreasing deque
2. the front of deque will always be the max value of the sliding windows
*/

class Solution {
public:
    
    void printDeque(deque<int> dq, vector<int> ans){
        for (auto it = dq.begin(); it != dq.end(); ++it){
            int idx = *it;
            cout << ' ' << ans[idx];
        }
        
        cout << endl;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if(k == 1){
            return nums;
        }
        
        int l = nums.size();
        
        if(l == 0 || k == 0){
            return vector<int>();
        }
        
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0; i < l; ++i){
            
            // move sliding window
            if(!dq.empty() && dq.front() == i - k){
                dq.pop_front();
            }
            // maintain monotone dq
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            
            // add current to back
            dq.push_back(i);
            
            if(i - k + 1 >= 0){
                ans.push_back(nums[dq.front()]);
            }
            //printDeque(dq, nums);
        }
        
        return ans;   
    }
};