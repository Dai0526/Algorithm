class WordDistance {
public:
    
    WordDistance(vector<string>& words) {       
        for(int i = 0; i < words.size(); ++i){
            m_record[words[i]].push_back(i);
        }       
    }
    
    int shortest(string word1, string word2) {
        
        if(m_record.find(word1) == m_record.end() || m_record.find(word2) == m_record.end()){
            return -1; // pd says that it muse in map
        }
        
        vector<int> idx1s = m_record[word1];
        vector<int> idx2s = m_record[word2];
        
        int ptr1 = 0;
        int ptr2 = 0;
        int minDiff = numeric_limits<int>::max();
        
        while(ptr1 < idx1s.size() && ptr2 < idx2s.size()){
            
            int pos1 = idx1s[ptr1];
            int pos2 = idx2s[ptr2];
            
            minDiff = min(minDiff, abs(pos1 - pos2));
            
            if(pos1 < pos2){
                ++ptr1;
            }else{
                ++ptr2;
            }
        }
        
        return minDiff;
    }
    
    
private:
    
    unordered_map<string, vector<int>> m_record;
    
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */