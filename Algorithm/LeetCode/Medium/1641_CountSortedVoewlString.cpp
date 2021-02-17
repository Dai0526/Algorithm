
/*
    1641. Count Sorted Vowel Strings
    https://leetcode.com/problems/count-sorted-vowel-strings/
*/

#include <vector>
using namespace std;
class Solution {
    
public:
    
    /*
    memorization can be implemented as a look up table-> dynamic programming bottom up
    f(n, vol) = f(n - 1, vol) + f(n, vol - 1);
    Base case: f(n, 1) = 1, f(1, vol) = vol
    
    further improvement is to use 1D vector, and use potiner to do it.
    */
    int countVowelStrings(int n){
        const int VOL = 5;
        
        int col = VOL + 1;
        int row = n + 1;
        
        vector<vector<int>> lut(row, vector<int>(col, 0)); // +1 for better understanding
        
        // init n = 1
        for(int j = 1; j < col; ++j){
            lut[1][j] = j;
        }
        
        // init vol = 1
        for(int i = 1; i < row; ++i){
            lut[i][1] = 1;
        }
        
        for(int i = 2; i < row; ++i){
            for(int j = 2; j < col; ++j){
                lut[i][j] = lut[i][j - 1] + lut[i - 1][j];
            }
        }
  
        return lut[n][5];
    }
    
private:
    
    /* 
        recursive solution by pattern
        f(n, vol) = f(n - 1, vol) + f(n, vol - 1);
        Base case: f(n, 1) = 1, f(1, vol) = vol
        
        use memeorization to get already computed answer
    */
    
    int countVowelStrings_memo(int n) {
        vector<vector<int>> memo(n, vector<int>(5, 0));
        return recursivePattern(n, 5, memo);
    }
    
    int recursivePattern(int n, int vol, vector<vector<int>>& memo){
        if(n == 1){
            return vol;
        }
        
        if(vol == 1){
            return 1;
        }
        
        if(memo[n - 1][vol - 1] != 0){
            return memo[n - 1][vol - 1];
        }
        
        int res = recursivePattern(n - 1, vol, memo) + recursivePattern(n, vol - 1, memo);
        memo[n - 1][vol - 1] = res;
        return res;
    }

private:
    // brute force solution
    int countVowelStrings_bruteForce(int n) {
        return bruteForceSolution(n);
    }
    
    int bruteForceSolution(int n, int vol = 1){
        if(n == 0){
            return 1;
        }
        
        int result = 0;
        for(int i = vol; i <= 5; ++i){
            result += bruteForceSolution(n - 1, i);
        }
        
        return result;
    }

    
};