/*
https://leetcode.com/problems/assign-cookies/submissions/

Greedy Algorithm

Need to justify why Greedy Algorithm stands
1. because one child can only has exactly 1 cookie
2. Thus, a child must consume the next large cookies that is larger than its content.
3. Greedy stands since it is alway optimal to content the current smallest child one by one

two pointer to optimize

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        if(s.size() < 1){
            return false;
        }
        
        // sort 2 vecs by ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0, j = 0;
        
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i]){
                i++;
            }
            j++;
        }
        
        return i; 
    }
};