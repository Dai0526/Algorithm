/*
https://leetcode.com/problems/happy-number/

The core idea is to detect whether to know it cannot reach 1
1. hash_set
2. fast-slow see if meet
3. math -> hardcoded 

*/

#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> rec;
        
        while(n != 1){
            rec.insert(n);
            n = GetHappySum(n);
            
            if(rec.find(n) != rec.end()){
                return false;
            }
            
        }
        
        return true;
        
    }
    
    int GetHappySum(int n){
        int sum = 0;
        
        while(n > 0){
            int temp = n % 10;
            n = n / 10;
            sum += temp * temp;
        }
        
        return sum;
    }
};