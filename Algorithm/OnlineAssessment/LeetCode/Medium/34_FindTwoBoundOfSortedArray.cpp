/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Binary Search
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int len = nums.size();
        
        vector<int> ans { -1, -1 };
        
        if(len == 0){
            return ans;
        }
        
        if(target < nums[0] || target > nums[len - 1]){
            return ans;
        }
        
        
        // do binary search
        ans[0] = lowerBound(nums, target);
        ans[1] = upperBound(nums, target);
        cout << ans[1] << endl;
        return ans;
        
    }
    
private:
    int lowerBound(vector<int>& src, int target){
        int len = src.size();

        // Do binary search
        int l = 0;
        int r = len - 1;

        while(l < r){
            int mid = floor(l + (r - l) / 2.0);
            int curr = src[mid];

            if(curr < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        if(src[r] == target){
            return r;
        }

        return -1;  
    }
    
    int upperBound(vector<int>& src, int target){
        int len = src.size();

        // Do binary search
        int l = 0;
        int r = len - 1;

        while(l < r){
            int mid = ceil(l + (r - l) / 2.0);
            int curr = src[mid];

            if(curr > target){
                r = mid - 1;
            }
            else{
                l = mid;
            }
        }

        if(src[l] == target){
            return l;
        }

        return -1;  
    }
};