class Solution {
public:
    string reverseVowels(string s) {
        set<char> cset { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int l = 0;
        int r = s.length() - 1;
        
        while(l < r){
            while(l < r && cset.find(s[l]) == cset.end()){
                ++l;
            }
            
            while(l < r && cset.find(s[r]) == cset.end()){
                --r;
            }
            
            if(l < r){
                //swap
                char temp = s[r];
                s[r] = s[l];
                s[l] = temp;
            }else{
                break;
            }
            
            ++l;
            --r;
            
        }
        
        return s;
        
    }
};