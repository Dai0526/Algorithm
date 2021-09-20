
/*
https://leetcode.com/problems/longest-common-subsequence/
we can apply DP to it, since the result[i][j] is based on previous result[i-1][j], result[i][j-1], and result[i-1][j-1]

Here is the transfer function


init a lut[m + 1][n + 1]

Top to bottom
    a b c d e
  0 0 0 0 0 0
a 0
b 0
c 0

if txt1[i - 1] == txt2[j - 1]
    lut[i][j] = lut[i-1][j-1] + 1
else
    lut[i][j] = max(lut[i][j-1], lut[i-1][j])

bottom to top
 a b c d e f 
a            0
b            0
c            0
 0 0 0 0 0 0 0

if txt1[i - 1] == txt2[j - 1]
    lut[i][j] = lut[i-1][j-1] + 1
else
    lut[i][j] = max(lut[i][j+1], lut[i+1][j])



*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // we do top to down
        int l1 = text1.length();
        int l2 = text2.length();
        
        // init
        vector<vector<int>> lut(l1 + 1, vector<int>(l2 + 1, 0));
        
        for(int i = 1; i < l1 + 1; ++i){
            for(int j = 1; j < l2 + 1; ++j){
                if(text1[i - 1] == text2[j - 1]){
                    lut[i][j] = lut[i - 1][j - 1] + 1;
                }else{
                    lut[i][j] = max(lut[i - 1][j], lut[i][j - 1]);
                }
            }
        }
                
        return lut[l1][l2];
    }
};