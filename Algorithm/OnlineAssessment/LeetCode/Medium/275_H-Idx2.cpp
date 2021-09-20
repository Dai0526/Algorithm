/*
 Binary Search
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        int left = 0;
        int right = n - 1;
        int hIdx = 0;
        while(left < right - 1){
            int mid = left + (right - left) / 2;
            int midCita = citations[mid];
            
            hIdx = n - mid;
            
            if(midCita >= hIdx){
                right = mid;
            }else{
                left = mid;
            }
        }
        
        hIdx = n - left;
        if(citations[left] >= hIdx){
            return hIdx;
        }
        
        hIdx = n - right;
        if(citations[right] >= hIdx){
            return hIdx;
        }
        
        return 0;
    }
};