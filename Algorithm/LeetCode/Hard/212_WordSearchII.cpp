/*
https://leetcode.com/problems/word-search-ii/
Use Trie as data structure
DFS and backtracking to check each char on board as start
*/

class Solution {
    
public:
    struct TrieNode{
        bool isWord;
        vector<TrieNode*> children;
        
        TrieNode(){
            isWord = false;
            children = vector<TrieNode*>(26, nullptr);
        }
    };
    
    
public:
    const char US = 0x31;
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if(words.size() == 0 || board.size() == 0 || board[0].size() == 0){
            return ans;
        }
        
        TrieNode trie;
        TrieNode* pTrie = &trie;
        pTrie = buildTrie(words);
        
        int r = board.size();
        int c = board[0].size();
        unordered_set<string> visited;
        
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                TrieNode* pRoot = pTrie;
                find(board, i, j, pRoot, "", visited, ans);
            }
        }
        
        return ans;
        
    }
private:
    // dfs
    void find(vector<vector<char>>& board, int r, int c, TrieNode* root, string word, unordered_set<string>& visited, vector<string>& result){
        int nRow = board.size();
        int nCol = board[0].size();
        
        if(r < 0 || r >= nRow || c < 0 || c >= nCol){
            return;
        }
        
        char ch = board[r][c];
        if(ch == US){
            // already visited
            return;
        }
        
        int idx = ch - 'a';
        if(root->children[idx] == nullptr){
            return;
        }
        
        word += ch;
        
        root = root->children[idx];
        
        if(root->isWord && visited.find(word) == visited.end()){
            result.push_back(word);
            visited.insert(word);
        }
        
        // mark visited in board
        board[r][c] = US;
        find(board, r + 1, c, root, word, visited, result);
        find(board, r - 1, c, root, word, visited, result);
        find(board, r, c + 1, root, word, visited, result);
        find(board, r, c - 1, root, word, visited, result);
        board[r][c] = ch;
    }
    
    
    TrieNode* buildTrie(vector<string>& words){
        TrieNode* root = new TrieNode();
        
        for(const string& s : words){
            TrieNode* temp = root;
            
            for(char c : s){
                int idx = c - 'a';
                if(temp->children[idx] == nullptr){
                    temp->children[idx] = new TrieNode();
                }
                temp = temp->children[idx];
            }
            
            temp->isWord = true;
        }
        
        return root;
    }
};
