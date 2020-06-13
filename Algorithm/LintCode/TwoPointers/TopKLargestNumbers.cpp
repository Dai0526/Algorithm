#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param k: An integer
     * @return: the top k largest numbers in array
     */
    vector<int> topk(vector<int> &nums, int k) {
        // make a copy, do not affect original vector
        int nSize = nums.size();
        vector<int> workingVec(nums);
        
        quickSort(workingVec, 0, nSize - 1);
        
        vector<int> result;
        for(int i = nSize - 1; i > nSize - 1 - k; --i){
            result.push_back(workingVec[i]);
        }
        
        return result;    
    }
    
    void quickSort(vector<int>& vec, int start, int end){
        if(start >= end){
            return;
        }
        
        int left = start;
        int right = end;
        
        int pivotIdx = left + (right - left) / 2;
        int partition = vec[pivotIdx];
        
        while(left <= right){
            while(vec[left] < partition && left <= right){
                ++left;
            }
                        
            while(vec[right] > partition && left <= right){
                --right;
            }
            
            if(left<=right){
                swap(vec, left, right);
                ++left;
                --right; 
            }

        }

        quickSort(vec, left, end);
        quickSort(vec, start, right);   
    }
    
    void swap(vector<int>& vec, int idx1, int idx2){
        int temp = vec[idx1];
        vec[idx1] = vec[idx2];
        vec[idx2] = temp;
    }
    

    void mergeSort(vector<int>& vec, int start, int end, vector<int>& out){
        
        if(start >= end){
            return;
        }
        
        mergeSort(vec, start, (start+end)/2, out);
        mergeSort(vec, (start + end)/2 + 1, end, out);

        mergeVec(vec, start, end, out);
    }

    void mergeVec(vector<int>& vec, int start, int end, vector<int>& out){
        int middle = (start + end) / 2;
        int leftIdx = start;
        int rightIdx = middle + 1;
        int idx = leftIdx;
        
        while(leftIdx <= middle && rightIdx <= end){
            if(vec[leftIdx] < vec[rightIdx]){
                out[idx++] = vec[leftIdx++];
            }else{
                out[idx++] = vec[rightIdx++];
            }
        }

        while(leftIdx <= middle){
            out[idx++] = vec[leftIdx++];
        }

        while(rightIdx <= end){
            out[idx++] = vec[rightIdx++];
        }

        for(int i = start; i <= end; ++i){
            vec[i] = out[i];
        }
    }

};