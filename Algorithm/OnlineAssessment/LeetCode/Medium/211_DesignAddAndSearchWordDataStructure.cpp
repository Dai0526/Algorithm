/*
https://leetcode.com/problems/design-add-and-search-words-data-structure/
Use Trie

Better space, average time complexity is better if space is large.

*/

#include <unordered_map>
using namespace std;
class WordDictionary {
    
struct TrieNode{
    
    unordered_map<char, TrieNode*> children;
    bool isExisted = false;
    
    TrieNode(){};
};
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        m_root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = m_root;
        
        for(char c : word){
            if(node->children.find(c) == node->children.end()){
                node->children[c] = new TrieNode(); // init map
            } 
            
            node = node->children[c];
        }
        
        node->isExisted = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchNode(word, 0, m_root);
    }

    bool searchNode(const string& word, int begin, TrieNode* node){
        for(int i = begin; i < word.length(); ++i){
            char ch = word[i];
            
            if(ch == '.'){
                // search all node
                for(const pair<char, TrieNode*>& p : node->children){
                    if(searchNode(word, i + 1, p.second)){
                        return true;
                    }
                }  
                
                return false;
                
            }else{
                if(node->children.find(ch) == node->children.end()){
                    return false;
                }
                
                node = node->children[ch];
            }
        }
        
        return node->isExisted;
    }
    
private:
    
    TrieNode* m_root;

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */