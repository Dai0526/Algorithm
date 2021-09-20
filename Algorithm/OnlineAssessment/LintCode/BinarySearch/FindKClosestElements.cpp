#include <vector>

using namespace std;

class Solution {
/*
idea:

find the closest item first by using binary search, then use two pointers, 
move left right to compare until all found

*/  
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        int len = A.size();

        int left = 0;
        int right = len - 1;
        int mid = 0;

        // binary search
        while(left + 1 < right){
            mid = left + (right - left) / 2;

            if(A[mid] >= target){
                right = mid;
            }else{
                left = mid;
            }
        }

        // Find the item that is closest grater than target. That's why start from left
        int idx;

        if(abs(target - A[left]) < abs(target - A[right])){
            idx = left;
        }else{
            idx = right;
        }
        
        vector<int> out;
        // target is less than any element in list, add 0 to k-1
        if(idx == 0 && A[idx] >= target){
            for(int i = 0; i < k; ++i){
                out.push_back(A[i]);
            }
            return out;
        }

        // target is grater than any element in list, add 0 to k-1
        if(idx == len - 1 && A[idx] <= target){
            for(int i = len - 1; i >= len - k; --i){
                out.push_back(A[i]);
            }
            return out;
        }

        
        // set two pointers

        if(idx == 0){
            idx += 1;
        }
        int front = idx - 1;
        

        for(int i = 0; i < k; ++i){
            if(front < 0){
                out.push_back(A[idx++]);
            }else if(idx > len - 1){
                out.push_back(A[front--]);
            }else{
                int val = target - A[front] <= A[idx] - target ? A[front--] : A[idx++];
                out.push_back(val);
            }
        }

        return out;
    }
};