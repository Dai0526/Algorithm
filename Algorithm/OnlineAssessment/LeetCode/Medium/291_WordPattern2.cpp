/*
Use two hash map to match pattern and string

1. for not recorded char-string match,
do backtracking for each possible candidate, 

recursion return true if both pattern and string goes to the end.

*/

class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> csmap;
        unordered_map<string, char> scmap;
        
        return dfs(pattern, 0, s, 0, csmap, scmap);
        
    }
    
    
    bool dfs(string pattern, int pIdx, string str, int sIdx, unordered_map<char, string>& csmap, unordered_map<string, char>& scmap){
        
        if(pIdx == pattern.size()){
            return sIdx == str.size();    
        }
        
        char ptrn = pattern[pIdx];
        
        // if key already matched
        if(csmap.find(ptrn) != csmap.end()){
            string match = csmap[ptrn];
            
            if(str.substr(sIdx, min(match.size(), str.size() - sIdx)).compare(match) == 0){
                return dfs(pattern, pIdx + 1, str, sIdx + match.size(), csmap, scmap);
            }else{
                return false;
            }
        }else{
            // not found
            // do back tracking for each possible candidate match
            for(int i = sIdx; i < str.size(); ++i){
                string candidate = str.substr(sIdx, i - sIdx + 1);
                if(scmap.find(candidate) != scmap.end()){
                    continue;
                }
                
                // add to record
                csmap[ptrn] = candidate;
                scmap[candidate] = ptrn;
                
                if(dfs(pattern, pIdx + 1, str, sIdx + candidate.size(), csmap, scmap) == true){
                    return true;
                }
                
                // not match, then pop
                csmap.erase(ptrn);
                scmap.erase(candidate);
            }    
        }
        
        return false;
    }
    
    
};