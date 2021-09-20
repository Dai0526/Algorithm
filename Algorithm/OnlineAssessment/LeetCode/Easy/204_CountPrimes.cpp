/*
https://leetcode.com/problems/count-primes/submissions/
https://leetcode.com/problems/count-primes/discuss/452628/SIEVE-OF-ERATOSTHENES-%2B-EXPLANATION-%2B-OPTIMIZATIONS

as we know 2 is smallest prime, then mark all 2 factors as false
repeat steps.

*/

#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2){
            return 0;
        }
        
        // prime less than n
        vector<bool> primes(n, true);
        primes[0] = false; // 0 is not prime
        primes[1] = false; // 1 is not prime
        
        //improve iteration times by sqrt(n)
        for(int i = 2; i < sqrt(n); ++i){
            if(primes[i] == true){
                int next = i + i;
                while(next < n){
                    primes[next] = false;
                    next += i;
                }
            } 
        }
        
        int cnt = count(primes.begin(), primes.end(), true);
        return cnt;   
    }
};