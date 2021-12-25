/*

1. virtual index with extra space
a. sort
b. seg arry by 2, two ptrs from end of both segs
c. put number in to new vec

2. math way - find median
a. find kth smallest to find median
b. 3 idxrs, i for iteration, j for odd(>median), k for even(< median)
c. compare with median and do swap


*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = (n - 1) / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        
        int median = nums[mid];
        
        int i = 0; // check all element
        int j = 1; // greater than median, in odd index
        int k = (n - 1) % 2 == 0? n - 1 : n - 2; // less than median, must on even index
        
        while(i < n){
            if(nums[i] > median && (i % 2 == 0 || i > j)){
                swap(nums[i], nums[j]);
                j += 2;
            }else if(nums[i] < median && (i % 2 == 1 || i < k)){
                swap(nums[i], nums[k]);
                k -= 2;
            }else{
                ++i;
            }
        }     
    }
    
    
    void swap(int& l, int& r){
        int temp = l;
        l = r;
        r = temp;
    }
};