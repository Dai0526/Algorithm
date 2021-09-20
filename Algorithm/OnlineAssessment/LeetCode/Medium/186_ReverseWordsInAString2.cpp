/*
https://leetcode.com/problems/reverse-words-in-a-string-ii/

1. A method to reverse vector in-place
2. Rever whole vector
3. update left, and right, if there is a char c == ' '
    then swap left, right 

*/

class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        int n = s.size();
        if(n < 2){
            return;
        }
                
        // reverse whole string first
        reverse(s, 0 , n - 1);

        int left = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                reverse(s, left, i - 1);
                left = i + 1;
                continue;
            }
        }

        if(left != n - 1){
            reverse(s, left, n - 1);
        }
    }
    
    
    void reverse(vector<char>&s, int l, int r){
        while(l < r){
            
            // swap
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            
            ++l;
            --r;
        }
    }
    
};