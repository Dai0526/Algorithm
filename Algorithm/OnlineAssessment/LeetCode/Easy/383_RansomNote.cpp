/*
construct map 
remove count 

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magaMap;
        
        for(char c : magazine){
            ++magaMap[c];
        }
        
        for(char c : ransomNote){
            if(magaMap.find(c) == magaMap.end()){
                return false;
            }
            
            if(magaMap[c] == 0){
                return false;
            }
            
            --magaMap[c];
            
        }
        
        
        return true;
        
    }
};