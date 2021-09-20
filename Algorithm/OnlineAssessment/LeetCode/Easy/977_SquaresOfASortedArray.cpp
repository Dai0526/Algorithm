/*
https://leetcode.com/problems/squares-of-a-sorted-array/submissions/

Simple solution: square, then sort

Better solution
1. find positive part idx, 
2. Idea of merge two sorted list


*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int n = A.size();
        int posIdx = 0;
        
        while(posIdx < n && A[posIdx] < 0){
            ++posIdx;
        }
        
        int negIdx = posIdx - 1;
        
        //merge two sorted list
        vector<int> sorted;
        
        while(negIdx >=0 && posIdx < n){
            int neg = A[negIdx] * A[negIdx];
            int pos = A[posIdx] * A[posIdx];
            
            if(neg < pos){
                sorted.push_back(neg);
                --negIdx;
            }else{
                sorted.push_back(pos);
                ++posIdx;
            }
        }
        
        // finish up item left
        while(negIdx >= 0){
            sorted.push_back(A[negIdx] * A[negIdx]);
            --negIdx;
        }
        
        while(posIdx < n){
            sorted.push_back(A[posIdx] * A[posIdx]);
            ++posIdx;
        }
        
        
        return sorted;
    }
};