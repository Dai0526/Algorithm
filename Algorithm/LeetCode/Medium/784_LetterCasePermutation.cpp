/**
 * Backtracking - recursion 
 */

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        AddPermutation(ans, S, 0);
               
        return ans;
    }
    
    void AddPermutation(vector<string>& perms, string str, int idx){
        if(idx == str.size()){
            cout << "push " << str << endl;
            perms.push_back(str);
            return;
        }

        AddPermutation(perms, str, idx + 1);
        char curr = str[idx];
        if(!isdigit(curr)){
            str[idx] = islower(curr) ? toupper(curr) : tolower(curr);
            AddPermutation(perms, str, idx + 1);
        }
        
    }
    
};