/*
https://leetcode.com/problems/single-row-keyboard/
*/

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> keyIdxArry(26, -1);
        
        for(int i = 0; i < keyboard.size(); ++i){
            int idx = keyboard[i] - 'a';
            keyIdxArry[idx] = i;
        }
    
        int prev = 0;
        int sum = 0;
        
        for(char c : word){
            int next = keyIdxArry[c - 'a'];
            sum += abs(prev - next);
            prev = next;
        }
        
        
        return sum;
    }
};