/*
https://leetcode.com/problems/reformat-date/

Split to get token
Then transform each token and add to string

*/
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {

private: 
    vector<string> mon = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    
public:
    string reformatDate(string date) {
        // get tokens
        vector<string> tks;
        split(date, tks, ' ');
        
        stringstream ss;
        // set year
        ss << tks[2] << "-";
        
        // set month
        for(int i = 0; i < 12; ++i){
            if(tks[1].compare(mon[i]) != 0){
                continue;
            }
            
            if(i < 9){
                ss << "0";
            }
            
            ss << to_string(i + 1); 
        }
        
        ss << "-";
        
        // set days
        if(tks[0].size() == 3){
            ss << "0" << tks[0][0];
        }else{
            ss << tks[0][0] << tks[0][1];
        }
        
        return ss.str();
        
    }
    
    void split(const string& s, vector<string>& tks, char deli){
        istringstream iss(s);
        string temp = "";
        while(getline(iss, temp, deli)){
            tks.push_back(temp);
        }
    }
    
    void split2(const string& s, vector<string>& tks){
        string temp = "";
        for(char c : s){
            if(c == ' '){
                tks.push_back(temp);
                temp = "";
            }else{
                temp += c;
            }
        }
        tks.push_back(temp);
    }
};