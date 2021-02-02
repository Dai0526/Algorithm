/*
3 ptrs problems

*/

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        
        int n = arr.size();
        int count = 0;
        for(int i = 0; i < n - 2; ++i){
            for(int j = i + 1; j < n - 1; ++j){
                for(int k = j + 1; k < n; ++k){
                    if(validate(arr[i], arr[j], arr[k], a, b, c)){
                        ++count;
                    }
                }
            }
        }
        
        return count;
    }
    
    
    bool validate(int fst, int snd, int trd, int a, int b, int c){
        if(abs(fst - snd) <= a && abs(snd - trd) <= b && abs(fst - trd) <= c){
            return true;
        }
        
        return false;
    }
    
};