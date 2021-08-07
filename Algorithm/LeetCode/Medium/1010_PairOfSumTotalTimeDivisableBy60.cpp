/*
(a + b) % c = (a % c + b % c) % c
two cases:
1. a % 60 = 0 and b % 60 = 0
2. a % 60 + b % 60 = 60

*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int n = time.size();
        int nPair = 0;
        unordered_map<int, int> remMap;
        
        for(int i = 0; i < n; ++i){
            int a = time[i];
            int rem = a % 60;
                       
            int compRem = (rem == 0) ? 0 : 60 - rem;
            
            if(remMap.find(compRem) != remMap.end()){
                nPair += remMap[compRem];
            }
            
            ++remMap[rem];
        }
        
        return nPair;
    }
};