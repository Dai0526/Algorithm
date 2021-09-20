/*
65. Median of two Sorted Arrays
https://www.lintcode.com/problem/median-of-two-sorted-arrays/
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.

Example 1
Input:
A = [1,2,3,4,5,6]
B = [2,3,4,5]
Output: 3.5

Example 2
Input:
A = [1,2,3]
B = [4,5]
Output: 3
Challenge
The overall run time complexity should be O(log (m+n)).

Clarification
The definition of the median:

The median here is equivalent to the median in the mathematical definition.
The median is the middle of the sorted array.
If there are n numbers in the array and n is an odd number, the median is A[(n-1)/2].
If there are n numbers in the array and n is even, the median is (A[n / 2] + A[n / 2 + 1]) / 2.
For example, the median of the array A=[1,2,3] is 2, and the median of the array A=[1,19] is 10.

思路 
      L1      R1
A: 3   5   |   8   9
        L2         R2
B: 1   2   7   |   10   11   12

FINAL 1  2  3  5  7  |  8  9  10  11  12

LenTotal = LenA + LenB
*cutA A左边有几个元素
*cutB B左边有几个元素

binary search的范围
(cutL，cutR) 对于 CutA的左右界限

1.确定cutA
2. 二分法得到cutA后， cutB = totalLen / 2 - cutA
3. 切完得到四个值L1, R1, L2, R2
    L1 = A[cutA - 1];
    R1 = A[cutA];
            
    L2 = B[cutB - 1];
    R2 = B[cutB];


分情况
1. 满足L1 <= R2 && L2 <= R1 可能是

2. 如果L1 > R2, cutA左移 ---> (cutL，cutR) = (cutL, cutA - 1)
           L1     R1
A: 3   5   8   |   9
       L2      R2
B: 1   2   |   7   10   11   12

3. 如果L2 > R1, cutB右移 ---> (cutL，cutR) = (cutA + 1, cutR)

*/

#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        if(A.size() > B.size()){
            return findMedianSortedArrays(B,A);
        }

        int lenA = A.size();
        int lenB = B.size();
        
        if(lenA == 0){
            return (B[(lenB - 1) / 2] + B[lenB / 2]) / 2.0;
        }

        
        int totalLen = lenA + lenB;

        int cutA = 0;
        int cutB = 0;

        int cutL = 0;
        int cutR = lenA;

        while(cutA <= lenA){
            cutA = cutL + (cutR - cutL) / 2;
            cutB = totalLen / 2 - cutA;

            double L1 = (cutA == 0) ? numeric_limits<int>::min() : A[cutA - 1];
            double R1 = (cutA == lenA) ? numeric_limits<int>::max() : A[cutA];
            
            double L2 = (cutB == 0) ? numeric_limits<int>::min() : B[cutB - 1];
            double R2 = (cutB == lenB) ? numeric_limits<int>::max() : B[cutB];

            if(L1 > R2){
                cutR = cutA - 1;
            }else if(L2 > R1){
                cutL = cutA + 1;
            }else{
                if(totalLen % 2 == 0){
                    L1 = L1 > L2 ? L1 : L2;
                    R1 = R1 < R2 ? R1 : R2;
                    return (L1 + R1)/2;
                }else{
                    R1 = R1 < R2? R1 : R2;
                    return R1;
                }
            }
        }
        return -1;
    }
};