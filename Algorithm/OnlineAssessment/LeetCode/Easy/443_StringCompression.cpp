/*
https://leetcode.com/problems/string-compression/

Tricky edge case

*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        
        if(chars.size() == 0){
            return 0;
        }
           
        char prev = chars[0];
        int idx = 1;
        int count = 1;
        
        for(int i = 1; i < chars.size(); ++i){
            char temp = chars[i];
            if(temp == prev){
                ++count;
                continue;
            }
                
            // set count
            if(count == 1){
                prev = temp;
                chars[idx] = temp;
                ++idx;
            }else{
                
                string cntStr = to_string(count);
                for(char c : cntStr){
                    chars[idx] = c;
                    ++idx;
                }

                // reset status
                chars[idx] = temp;
                ++idx;
                count = 1;
                prev = temp;
            }
   
        }
        
        if(count != 1){
            
            string cntStr = to_string(count);
            for(char c : cntStr){
                chars[idx] = c;
                ++idx;
            }
            
            return idx;
        }

        
        return idx;
        
    }
    
    
};