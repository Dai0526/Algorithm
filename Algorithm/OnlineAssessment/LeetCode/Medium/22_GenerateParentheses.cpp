class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0){
            return vector<string>();
        }
        
        
        vector<string> ans;
        vector<char> curr;
        dfs(ans, 0, 0, n, 2 * n, curr);
        
        return ans;
        
    }
 
private:
    
    void dfs(vector<string>& ans, int open, int close, int n, int len, vector<char>& curr){
        if(curr.size() == len){
            ans.push_back(vec2str(curr));
            return;
        }
        
        if(open < n){
            curr.push_back('(');
            dfs(ans, open + 1, close, n, len, curr);
            curr.pop_back();
        }
        
        if(close < open){
            curr.push_back(')');
            dfs(ans, open, close + 1, n, len, curr);
            curr.pop_back();
        }
        
    }

    
    string vec2str(const vector<char>& vec){
        stringstream ss;
        for(char c : vec){
            ss << c;
        }
        return ss.str();
    }
    
};