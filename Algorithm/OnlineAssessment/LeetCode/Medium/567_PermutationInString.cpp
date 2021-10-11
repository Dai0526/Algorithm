class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1 > l2){
            return false;
        }
        
        vector<int> s1Char(26, 0);     
        vector<int> s2Char(26, 0);

        int left = 0;
        int right = 0;
        
        // fillout s1 char sets
        while(right < l1){
            ++s1Char[s1[right] - 'a'];
            ++s2Char[s2[right] - 'a'];
            ++right;
        }
        
        
        // sliding window make charsets 2 to check if match
        --right;
        while(right < l2){
            if(s1Char == s2Char){
                return true;
            }
            
            ++right;
            if(right != l2){
                ++s2Char[s2[right] - 'a'];
                --s2Char[s2[left] - 'a'];
            }
            
            ++left;   
        }
        
        return false;
    }
};