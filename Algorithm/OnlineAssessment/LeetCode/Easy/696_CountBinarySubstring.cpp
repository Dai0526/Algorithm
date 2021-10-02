class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1;
        int other = 0;
        int ans = 0;
        
        for(int i = 1; i < s.length(); ++i){
            if(s[i] == s[i - 1]){
                ++curr;
                continue;
            }
            
            ans += min(curr, other); // first different will not count by adding 0
            
            other = curr;
            curr = 1;
            
        }
        
        ans += min(curr, other);
        
        return ans;
    }
};