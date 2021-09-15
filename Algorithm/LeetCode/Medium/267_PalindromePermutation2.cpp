/*
1. it must be a palindromes capable string
2. take have of the string, do permutations


*/


class Solution {
public:
    
    vector<string> generatePalindromes(string s) {
        
        unordered_map<char, int> freq;
        for(char c : s){
            ++freq[c];
        }
        
        int oddCount = 0;
        char mid = 0;
        string target;
        for(auto pr : freq){
            if(pr.second % 2 != 0){
                mid = pr.first;
                ++oddCount;
            }
            
            if(oddCount > 1){
                return vector<string>(); // not capable of palindromes
            }
    
            target += string(pr.second / 2, pr.first);   
        }
        
        
        vector<string> pali;
        unordered_set<int> visited;
        vector<char> perm;
        GetPali(target, visited, perm, pali);
        
        unordered_set<string> dup;
        vector<string> ans;
        for(string str : pali){
            
            if(dup.find(str) != dup.end()){
                continue;
            }
            
            dup.insert(str);
            
            string temp(str);
            reverse(str.begin(), str.end());
            
            str = mid == 0 ? str + temp : str + mid + temp;
            ans.push_back(str);
            //cout << str << endl;
        }
        
        return ans;
        
    }
    
    void GetPali(string& s, unordered_set<int>& visited, vector<char>& temp, vector<string>& pali){
        if(s.length() == temp.size()){
            pali.push_back(string(temp.begin(), temp.end()));
            return;
        }
        
        for(int i = 0; i < s.length(); ++i){
            if(visited.find(i) != visited.end()){
                continue;
            }
                        
            visited.insert(i);
            temp.push_back(s[i]);
            GetPali(s, visited, temp, pali);
            temp.pop_back();
            visited.erase(i);
        }
        
    }
    
};