/*
https://leetcode.com/articles/reverse-string/
*/

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if(s.size() == 0){
            return;
        }
        
        int left = 0;
        int right = s.size() - 1;
        
        while(left + 1 < right){
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        
        swap(s[left], s[right]);
        
    }
    
    void swap(char& a, char& b){
        char temp = a;
        a = b;
        b = temp;
    }
};

