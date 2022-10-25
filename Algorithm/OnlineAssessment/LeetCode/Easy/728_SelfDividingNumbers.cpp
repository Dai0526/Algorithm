/*
https://leetcode.com/problems/self-dividing-numbers/
Brute Force
*/

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> ans;
        
        for(int i = left; i < right + 1; ++i){
            if(isSelfDiv(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
    
    bool isSelfDiv(int n){
        
        int temp = n;
        while(temp > 0){
            int dig = temp % 10;
            
            if(dig == 0 || n % dig != 0){
                return false;
            }
            
            temp = temp / 10;
        }
        
        return true;
        
    }
    
};