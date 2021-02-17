
#include <vector>
#include <iostream>

using namespace std;

class Trie {

public:
    struct TrieNode{
        public:
            bool isWord;
            vector<TrieNode*> next;
        
            TrieNode(){
                isWord = false;
                next.resize(26, nullptr);
            }
    };
    
public:
    /** Initialize your data structure here. */
    Trie() {
        m_trie = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = m_trie;
        
        for(char c : word){
            if(temp->next[c - 'a'] == nullptr){
                temp->next[c - 'a'] = new TrieNode();
            }
            
            temp = temp->next[c - 'a'];
        }
        temp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = m_trie;
        
        for(char c : word){
            if(temp->next[c - 'a'] == nullptr){
                return false;
            }
            
            temp = temp->next[c - 'a'];
        }
        
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = m_trie;
        for(char c : prefix){
            if(temp->next[c - 'a'] == nullptr){
                return false;
            }
            
            temp = temp->next[c - 'a'];
        }
        return true;
    }

private:

    TrieNode* m_trie;        
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */