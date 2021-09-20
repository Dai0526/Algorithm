/*
https://leetcode.com/problems/median-of-two-sorted-arrays/
https://www.youtube.com/watch?v=do7ibYtv5nk

Want O(log (m+n)), thus it must be binary search

Base Idea, find the max for the first part, and min from second part.
e.g  1   2   3   4  |  5   6   7   8
4 is max of part1
5 is min of part2
Then medium is (4 + 5) / 2 = 4.5
----------------------------------------
Now we work on two arrays, we cut on both array, maintain 
    1. left of cutA and left of cutB is part 1
    2. right of cutA and right of cutB is part 2
    
        L1     R1          
l1:  1   3  |  5   7   
           cutA
        L2     R2     
l2:  2   4  |  6   8 
          cutB
                   
Assume merged
1   2   3   4  |  5   6   7   8
       L1  L2   R1  R2  
       
       
Thus, problem becomes how to cut A and cut B
Fact: It is O(min(m,n)), it do binary search on min vector.

1. if we know how to CutA, then we know how to cutB -> due to sizeA == sizeB
    *CutB = totalLen / 2 - CutA
2. For the right cut, it meets
    *L1 <= R2 && L2 <= R1
    
3. If L1 > R2 -> CutR = CutA - 1
    cutA左移 ---> (cutL，cutR) = (cutL, cutA - 1)
           L1     R1
A: 3   5   8   |   9
       L2      R2
B: 1   2   |   7   10   11   12

4. If L2 > R1 -> CutL = CutA + 1
    cutA右移 ---> (cutL，cutR) = (cutA + 1, cutR)
*/

#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // always working on small size array
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int lenA = nums1.size();
        int lenB = nums2.size();
        
        if(lenA == 0){
            return (nums2[(lenB - 1)/2] + nums2[lenB / 2]) / 2.0F;
        }
        
        int totalLen = lenA + lenB;
        
        //do binary search on both nums1 and nums2
        int cutA = 0;
        int cutB = 0;
        
        int cutL = 0;
        int cutR = lenA;
        
        while(cutA <= lenA){
            
            // do binary search on nums1
            cutA = cutL + (cutR - cutL) / 2;
            // do binary search on nums2
            cutB = totalLen / 2 - cutA;
            
            double L1 = cutA == 0 ? numeric_limits<int>::min() : nums1[cutA - 1];
            double R1 = cutA == lenA ? numeric_limits<int>::max() : nums1[cutA];
            
            double L2 = cutB == 0 ? numeric_limits<int>::min() : nums2[cutB - 1];
            double R2 = cutB == lenB ? numeric_limits<int>::max() : nums2[cutB];
            
            if(L1 > R2){
                cutR = cutA - 1;
            }else if(L2 > R1){
                cutL = cutA + 1;
            }else{
                if(totalLen % 2 == 0){
                    L1 = L1 > L2 ? L1 : L2;
                    R1 = R1 < R2 ? R1 : R2;
                    return (L1 + R1) / 2;
                }else{
                    R1 = R1 < R2 ? R1 : R2;
                    return R1;
                }
            }
            
        }
        return -1;
    }
};