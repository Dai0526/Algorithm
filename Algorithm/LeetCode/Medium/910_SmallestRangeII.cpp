/*

Get Possible pair of (smallest)largest and (largest)smallest, then compute min

largest is always the tail of sorted list
smallest depends on consecutive values ai + k ai+1 - k

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        
        if(nums.size() < 2){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int tail = nums[n - 1];
        int head = nums[0];
        int minRange = tail - head;
        
        for(int i = 0; i < n - 1; ++i){
            int largest = max(tail - k, nums[i] + k);
            int smallest = min(head + k, nums[i + 1] - k);
            minRange = min(minRange, largest - smallest);
        }
        
        return minRange;
    }
};