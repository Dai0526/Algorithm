/*
https://leetcode.com/problems/interleaving-string/
*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        int l3 = s3.length();
        
        if(l1 + l2 != l3){
            return false;
        }
        // init
        vector<vector<bool>> lut(l1 + 1, vector<bool>(l2 + 1, false));
        lut[0][0] = true;
        
        for(int i = 1; i < l1 + 1; ++i){
            lut[i][0] = lut[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        
        for(int j = 1; j < l2 + 1; ++j){
            lut[0][j] = lut[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        for(int i = 1; i < l1 + 1; ++i){
            for(int j = 1; j < l2 + 1; ++j){
                lut[i][j] = (lut[i - 1][j] && s1[i - 1] == s3[i + j - 1]) 
                         || (lut[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        
        return lut[l1][l2];
    }
};