/*
159. Find Minimum in Rotated Sorted Array
https://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array/
Suppose a sorted array in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.

Example 1:
Input：[4, 5, 6, 7, 0, 1, 2]
Output：0
Explanation：
The minimum value in an array is 0.

Example 2:
Input：[2,1]
Output：1
Explanation：
The minimum value in an array is 1.
Notice
You can assume no duplicate exists in the array.

思路：
二分法

注意不用情况情况
正常排序 123456
有旋转   456123

找到需要对比的值 -> 和哪个去对比？ 和 最右对比
left, right , mid

分析 为什么找最小值要和最右比
如果中间比右边大，那说明有旋转，那[left <-> mid]这一段一定都大于right, 所以要舍去，于是 left = mid
如果中间比右边小，那能保证 [mid <-> right] 那一段都大，所以right = mid

最后去判断left和right的值，最后剩下的情况可能是
456123
left = 1, right = 2
left = 6, right = 1
所以对比left right 就好

*/

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        //do a binary search
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right]){
                left = mid;
            }else{
                right = mid;
            }
        }
        
        
        if(nums[left] <= nums[right]){
            return nums[left];
        }else{
            return nums[right];
        }
        
    }
};