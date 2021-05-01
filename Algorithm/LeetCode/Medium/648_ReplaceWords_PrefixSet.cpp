class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> roots;
        for(string s : dictionary){
            roots.insert(s);
        }
        
        vector<string> ans;
        
        vector<string> tokens;
        split(sentence, tokens, ' ');
        
        
        for(string s : tokens){
            bool found = false;
            
            // check each words
            for(int i = 1; i < s.size(); ++i){
                string prefix = s.substr(0, i);
                if(roots.find(prefix) != roots.end()){
                    //found
                    found = true;
                    ans.push_back(prefix);
                    break;
                }
            }
            
            if(!found){
                ans.push_back(s);
            }
        }
        
        // reconstruct string back
        if(ans.size() == 0){
            return "";
        }
        
        if(ans.size() == 1){
            return ans[0];
        }
        
        stringstream ss;
        ss << ans[0];
        
        for(int i = 1; i < ans.size(); ++i){
            ss << " " << ans[i];
        }
        
        return ss.str(); 
    }
    
    void split(string& s, vector<string>& out, char delim){
        std::istringstream iss(s);
        string token;
        while (std::getline(iss, token, delim))
        {
            out.push_back(token);
        }  
    }
    
};