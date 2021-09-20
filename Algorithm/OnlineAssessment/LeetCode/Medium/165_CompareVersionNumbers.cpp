/*
https://leetcode.com/problems/compare-version-numbers/

Split之后从major version开始比较。

*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        // split by .
        vector<string> r1;
        vector<string> r2;
        
        split(version1, r1, '.');
        split(version2, r2, '.');
        
        int l1 = r1.size();
        int l2 = r2.size();
        int l = min(l1, l2);
        
        int i = 0;
        for(i = 0; i < l; ++i){
            int ver1 = stoi(r1[i]);
            int ver2 = stoi(r2[i]);
            
            if(ver1 != ver2){
                return ver1 > ver2 ? 1 : -1;
            }
        }
        
        while(i < l1){
            if(stoi(r1[i]) > 0){
                return 1;
            }
            ++i;
        }
        
        while(i < l2){
            if(stoi(r2[i]) > 0){
                return -1;
            }
            ++i;
        }
        
        return 0;
    }
    
    void split(string &s, vector<string>& tks, char delm){
        istringstream iss(s);
        string token;
        while(std::getline(iss, token, delm)){
            tks.push_back(token);
        }
    }
    
};