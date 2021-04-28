/*
https://leetcode.com/problems/word-subsets/

idea: Count char freqency, and make a highest freq count collection.

Then go over A to check if all freq Count exist and less equal then the A_freq_count
*/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        
        vector<int> freq(26);
        vector<string> ans;
        
        if(B.size() == 0 || A.size() == 0){
            return ans;
        }
        
        // get freq
        for(string& s : B){
            vector<int> sFreq(26, 0);
            GetCharCount(s, sFreq);
            
            for(int i = 0; i < 26; ++i){
                if(sFreq[i] == 0){
                    continue;
                }
                
                freq[i] = max(freq[i], sFreq[i]);
            }
        }
        
        // compare each word in A
        for(string& s : A){
            vector<int> sFreq(26, 0);
            GetCharCount(s, sFreq);
            
            bool found = true;
            for(int i = 0; i < 26; ++i){
                if(sFreq[i] < freq[i]){
                    found = false;
                    break;
                }
            }
            
            if(found){
                ans.push_back(s);
            }
        }
        
        
        return ans;
    }
    
    void GetCharCount(string& str, vector<int>& vec){        
        for(char c : str){
            ++vec[c - 'a'];
        }
    }
};