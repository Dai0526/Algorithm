/*
1. brute force

2. (a + b) % 60 == 0 => (a % 60 + b % 60) % 60 == 0

*/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        unordered_map<int, int> freq;
        int count = 0;
        for(int i = 0; i < time.size(); ++i){
            int rem = time[i] % 60;            
            if(rem == 0){
                count += freq[0];
            }else{
                count += freq[60 - rem];
            }
            ++freq[rem];
        }
        
        return count;
    }
};