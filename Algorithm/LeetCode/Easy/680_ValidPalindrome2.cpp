/*
https://leetcode.com/problems/valid-palindrome-ii/

Target is whole string, two pointers check from left and right

if they are not equal, then check
    1. skip left
    2. skip right

*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;
        
        while(i < j){
            if(s[i] != s[j]){
                return isPalind(s, i + 1, j) || isPalind(s, i, j - 1);
            }
            
            ++i;
            --j;
        }
        
        
        return true;
    }
    
private:
    
    bool isPalind(const string& s, int left, int right){
        
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            ++left;
            --right;
        }
        
        return true;
    }
};