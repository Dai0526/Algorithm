/*
https://leetcode.com/problems/bulls-and-cows/
*/

#include <unordered_map>
#include <sstream>

using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secMap;
        unordered_map<char, int> gesMap;
        
        // get bulls;
        int nBulls = 0;
        for(int i = 0; i < secret.length(); ++i){
            if(secret[i] == guess[i]){
                ++nBulls;
            }else{
                // only save un-bull candidates
                ++secMap[secret[i]];
                ++gesMap[guess[i]];
            }

        }
        
        
        int nCows = 0;
        for(const pair<char, int>& pr : secMap){
            nCows += min(pr.second, gesMap[pr.first]);
        }
        
        stringstream ss;
        ss << nBulls << "A" << nCows << "B";
        
        return ss.str();
    }
};