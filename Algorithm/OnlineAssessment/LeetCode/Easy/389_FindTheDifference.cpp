class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> sMap;
        char target = 0;
        
        for(char c : s){
            ++sMap[c];
        }
        
        for(char c : t){
            if(sMap.find(c) == sMap.end() || sMap[c] == 0){
                target = c;
                break;
            }
            --sMap[c];
        }
        
        return target;
    }
};