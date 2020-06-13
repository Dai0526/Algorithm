/*

235. Prime Factorization
https://www.lintcode.com/problem/prime-factorization/
Prime factorize a given integer.

Example
Example 1:

Input: 10
Output: [2, 5]
Example 2:

Input: 660
Output: [2, 2, 3, 5, 11]
Notice
You should sort the factors in ascending order.


*/


#include <vector>
using namespace std;
class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        
        vector<int> pFacs;
        
        if(num == 0 || num == 1){
            return pFacs;
        }
        
        if(num < 0){
            num = -num;
        }
        
        int prime = 2;
        
        while(prime * prime <= num){
            //
            while(num % prime == 0){
                pFacs.push_back(prime);
                num = num / prime;
            }
            
            ++prime;
        }
        
        if(num > 1){
            pFacs.push_back(num);
        }
        
        return pFacs;
    }
};