class Solution {
public:
    
    struct TrieNode{
        unordered_map<char, TrieNode*> nodes;
        bool isRoot;
        
        TrieNode() {
            isRoot = false;
        }
    };
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode root;
        TrieNode* pRoot = &root;
        
        // build trie
        for(string s : dictionary){
            TrieNode* pTemp = pRoot;
            
            for(char c : s){
                if(pTemp->nodes.find(c) == pTemp->nodes.end()){
                    // not found
                    pTemp->nodes[c] = new TrieNode();
                }
                
                // move to next
                pTemp = pTemp->nodes[c];
            }
            
            pTemp->isRoot = true;
        }
        
        // search trie to build root sentence
        vector<string> tokens;
        split(sentence, tokens, ' ');
        
        stringstream ss;
        
        for(string& str : tokens){
            
            TrieNode* pCurr = pRoot;
            stringstream ssRoot;
            bool found = false;
            for(char c : str){
                if(pCurr->nodes.find(c) == pCurr->nodes.end()){
                    break;
                }
                
                ssRoot << c;
                pCurr = pCurr->nodes[c];
                
                if(pCurr->isRoot){
                    ss << ssRoot.str() << " ";
                    found = true;
                    break;
                }    
            }
            
            if(!found){
                ss << str << " ";
            }
        }
        
        string ans = ss.str();
        ans.pop_back();
        return ans;    
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