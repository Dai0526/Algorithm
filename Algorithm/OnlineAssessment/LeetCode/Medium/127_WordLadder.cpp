/*
A BFS for each ladder string

Need a set or map to avoid duplicated

for each char in orgin string, 
replace it from a to z, to see if it is in wordlist
    if found , return count
    if in word list, add it to Queue, and keep doing

*/


#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()){
            return 0;
        }
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // get a char list from a - z
        vector<char> chars(26);
        for(int i = 0; i < 26; ++i){
            chars[i] = 'a' + i;
        }
        
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        int len = beginWord.length();
        int step = 1;
        
        while(!q.empty()){
            
            int qSize = q.size();
            
            //iterate each candidate
            for(int i = 0; i < qSize; ++i){
                string s = q.front();
                q.pop();
                
                if(s.compare(endWord) == 0){
                    // found, return ladder length
                    return step;
                }
                
                // tried to replace each char for the candidate, see if it is in list
                for(int j = 0; j < len; ++j){
                    char c = s[j];
                    
                    for(char temp : chars){     
                        //continue if no difference
                        if(temp == c){
                            continue;
                        }
                        
                        // replace the char
                        s[j] = temp;
  
                        if(visited.find(s) != visited.end() || wordSet.find(s) == wordSet.end()){
                            continue;
                        }
                               
                        q.push(s);
                        visited.insert(s);
                    }
                    
                    // convert it back for next idx's char
                    s[j] = c;
                }   
            }
            // for each level, increment step
            ++step;
        }
        
        // not found, return 0
        return 0;
    }

};