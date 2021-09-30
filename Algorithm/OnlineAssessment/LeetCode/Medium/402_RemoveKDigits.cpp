class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size() <= k){
            return "0";
        }
        
        stack<char> stk;
        for(char c : num){
            while(!stk.empty() && k > 0 && c < stk.top()){
                stk.pop();
                --k;
            }
            
            if(stk.empty() && c == '0'){
                continue;
            }
            
            stk.push(c);
        }
        
        
        while(k > 0 && !stk.empty()){
            stk.pop();
            --k;
        }
        
        stringstream ss;
        int len = stk.size();
        for(int i = 0; i < len; ++i){
            ss << stk.top();
            stk.pop();
        }
        
        string s = ss.str();
        
        if(s.length() == 0){
            return "0";
        }
        
        reverse(s.begin(), s.end());
        
        return s;
    }
};