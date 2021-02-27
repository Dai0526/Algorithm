/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
quick select O(N)
heap NLogN
sort NLogN

*/

#include <queue>

using namespace std;

class Solution {
    
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        // write your code here
        if(nums.size() == 0){
            return -1;
        }
        
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    
private:

    int quickSelect(vector<int>& nums, int left, int right, int k){
        if(left == right){
            return nums[left];
        }
        
        int i = left;
        int j = right;
        int pivot = nums[left + (right - left) / 2];
        
        while(i <= j){
            while(i <= j && nums[i] > pivot){
                ++i;
            }
            
            while(i <= j && nums[j] < pivot){
                --j;
            }
            
            if(i <= j){
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        
        // now left side of pivot is greater and right side are smaller
        //keep find the left hand side to get the kth greater 
        if(left + k - 1 <= j){
            return quickSelect(nums, left, j, k);
        }

        if(left + k - 1 >= i){
            return quickSelect(nums, i, right, k - (i - left));
            
        }

        return nums[j + 1];
    }

    
    void swap(int& a, int& b){
        if(a == b){
            return;
        }
        
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        
    }
    
public:
    int findKthLargest_quick(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());
        
        for(int i = 0; i < k - 1; ++i){
            maxHeap.pop();
        }     
        return maxHeap.top();
    }
    
};