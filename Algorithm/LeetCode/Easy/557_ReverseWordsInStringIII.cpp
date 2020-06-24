#include <vector>
#include <sstream>


using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // empty or a single character
        if(s.length() < 2){
            return s;
        }
         
        vector<string> words;
        split(s, words, ' ');
        
        stringstream ss;
        int n = words.size();
        for(int i = 0; i < n - 1; ++i){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            ss << temp << " ";
        }
        
        string temp = words[n - 1];
        reverse(temp.begin(), temp.end());
        ss << temp;
        
        return ss.str();
    }
    
    void split(string& s, vector<string>& tks, char delimeter){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delimeter))
        {
            tks.push_back(token);
        }   
    }
    
};