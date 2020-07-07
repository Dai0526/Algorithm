/*
https://leetcode.com/problems/fizz-buzz/submissions/
Simple string processing

*/
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> out;      
        for(int i = 1; i <= n; ++i){
                        
            stringstream ss;

            if(i % 3 == 0){
                ss << "Fizz";
            }
            
            if(i % 5 == 0){
                ss << "Buzz";
            }            
            
            string s = ss.str();
            
            if(s.empty()){
                out.push_back(to_string(i));
            }else{
                out.push_back(s);
            }            
        }
        
        return out;
    }
};