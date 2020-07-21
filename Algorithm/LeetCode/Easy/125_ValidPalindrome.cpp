/*
https://leetcode.com/problems/valid-palindrome/
Know how to use 
    isalnum(char c)
    tolower(char c)

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while(left < right){
            while(left < right && !isalnum(s[left])){
                ++left;
            }
            while(left < right && !isalnum(s[right])){
                --right;
            }
            
            
            if(left < right && tolower(s[left]) != tolower(s[right])){
                return false;
            }
            
            ++left;
            --right;
        }
        
        return true;
        
    }
};