class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length()){
            return false;
        }
        
        for(int i = 0; i < s.length(); ++i){
            if(s[i] != goal[0]){
                continue;
            }
            
            if(checkString(s, goal, i)){
                return true;
            }
            
        }
        
        return false;
        
    }
    
    bool checkString(string& s, string& goal, int start){
        
        int l = s.length();
        
        for(int i = 0; i < l; ++i){
            int sIdx = (start + i) % l;
            if(s[sIdx] != goal[i]){
                return false;
            }
        }
        
        return true;
        
    }
};