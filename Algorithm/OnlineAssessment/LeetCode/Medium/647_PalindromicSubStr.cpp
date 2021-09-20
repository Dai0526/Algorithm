/*
2 cases

idx as right
idx as mid


note that once pali is invlaid, break it, do not keep doing, it may have problem

e.g. "fdsklf"
whe idx = 4 as right.
sk - invalid
dskl - invalid
fdsklf - valid cause we only check s[left] == s[right]

*/
#include <iostream>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        int count = 0;
        int left, right;
        for(int i = 0; i < l; ++i){
            
            ++count;
            
            // idx as mid
            left = i - 1;
            right = i + 1; 
            while(left >=0 && right < l){
                if(s[left] == s[right]){
                    ++count;
                    --left;
                    ++right;
                }else{
                    break;
                }
            }
            
            
            // idx as right
            left = i - 1;
            right = i;
            while(left >=0 && right < l){
                if(s[left] == s[right]){
                    ++count;
                    --left;
                    ++right;
                }else{
                    break;   
                }
            }
        }
        
        return count;
    }
};