/*
https://leetcode.com/problems/advantage-shuffle/
*/

#include <queue>

using namespace std;

class Solution {
public:

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        int n = B.size();
        vector<int> ans(n, -1);
        multiset<int> s(A.begin(), A.end());
        for(int i = 0; i < B.size(); ++i){
            multiset<int>::iterator it = s.upper_bound(B[i]);
            if(it == s.end()){
                it = s.begin();
            }
            
            ans[i] = *it;
            s.erase(it);
        }
        
        return ans;
    }

    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
        vector<int> temp(A.begin(), A.end());
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        
        for(int i = 0; i < B.size(); ++i){
            vector<int>::iterator it;
            if(temp.back() > B[i]){
                it = upper_bound(temp.begin(), temp.end(), B[i]); // use binary search to find upper bound
            }else{
                it = temp.begin();
            }
            
            ans.push_back(*it);
            temp.erase(it);   
        }    
        
        return ans;
    }
    
};