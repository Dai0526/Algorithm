class Solution {
public:
    string toLowerCase(string s) {
        int low = static_cast<int>('A');
        int high = low + 25;
                
        for(char &c : s){
            if(c < low || c > high){
                continue;
            }
            
            c = tolower(c);
        }
        
        return s;
    }
};