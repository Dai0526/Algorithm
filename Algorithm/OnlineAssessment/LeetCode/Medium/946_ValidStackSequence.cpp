#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()){
            return false;
        }
        
        int n = pushed.size();
        stack<int> stk;
        int popIdx = 0;
        for(int i = 0; i < n; ++i){
            stk.push(pushed[i]);
            
            while(!stk.empty() && (stk.top() == popped[popIdx]) && (popIdx < n)){
                stk.pop();
                ++popIdx;
            }
        }
        
        return popIdx == n;
    }
};