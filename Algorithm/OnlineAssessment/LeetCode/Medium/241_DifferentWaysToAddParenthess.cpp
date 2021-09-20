/*
https://leetcode.com/problems/different-ways-to-add-parentheses/discuss/1294189/C%2B%2B-Solution-Faster-than-100-or-Explained-with-diagrams

*/

/*
Use dfs to build expression tree

1. check all chars
    a. if found operation sign
        1. split string into left and right parts
            the pattern will be {left number, sign, right number}
        2. compute result
2. if whole input string is a number, push to ans 


*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return dfs(input);
    }
    
    vector<int> dfs(string input){
        vector<int> ans;
        bool isNum = true;
        
        for(int i = 0; i < input.length(); ++i){
            
            char temp = input[i];
            
            if(!isdigit(temp)){
                
                isNum = false;
                
                vector<int> left = dfs(input.substr(0, i));
                vector<int> right = dfs(input.substr(i + 1));
                //cout << "left has " << left.size() << ", right has " << right.size()<< endl;
                
                for(int x : left){
                    for(int y : right){
                        //cout << "At i = " << i << ", compute x = " << x << ", y = " << y << ", op = " << temp << endl;
                        int val = calculate(x, y, temp);
                        ans.push_back(val);
                    }
                }
                
            }
        }
        
        
        if(isNum){
            ans.push_back(stoi(input));
        }
        
        return ans;
    }
    
    int calculate(int x, int y, char op){
        switch(op){
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            
        }
        return -1; // invalid
    }
    
};