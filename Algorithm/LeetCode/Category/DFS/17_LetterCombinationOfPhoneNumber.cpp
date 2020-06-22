/*

https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Backtracking to solve all combination problem!

for each digits, 
make a combination, 
then pass thourgh to recursion
pop up for back tracking.

*/


#include <map>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0){
            return vector<string>();
        }
        
        map<char, string> myMap;
        myMap['2'] = "abc";
        myMap['3'] = "def";
        myMap['4'] = "ghi";
        myMap['5'] = "jkl";
        myMap['6'] = "mno";
        myMap['7'] = "pqrs";
        myMap['8'] = "tuv";
        myMap['9'] = "wxyz";
         
        vector<string> out;
        vector<char> combi;
        
        dfs(digits, myMap, 0, combi, out);
        
        return out;
    }
    
    void dfs(const string& digits, map<char, string>& myMap, int idx, vector<char>& comb, vector<string>& out){
        if(idx == digits.length()){
            out.push_back(charVec2Str(comb));
            return;
        }
        
        for(char c : myMap[digits[idx]]){
            comb.push_back(c);
            dfs(digits, myMap, idx + 1, comb, out);
            comb.pop_back();
        }
        
    }
    
    string charVec2Str(const vector<char>& vec){
        stringstream ss;
        for(char c : vec){
            ss << c;
        }
        return ss.str();
    }
    
};