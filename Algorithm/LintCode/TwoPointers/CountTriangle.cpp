/*
382. Triangle Count
https://www.lintcode.com/problem/triangle-count/
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?

Example 1:
Input: [3, 4, 6, 7]
Output: 3
Explanation:
They are (3, 4, 6), 
         (3, 6, 7),
         (4, 6, 7)

Example 2:
Input: [4, 4, 4, 4]
Output: 4
Explanation:
Any three numbers can form a triangle. 
So the answer is C(3, 4) = 4


for a triangle, it requires a+b>c
Since it is a+b>c, then sort array, and iterate it backwards.
like a 3sum problem, convert it to 2sum, loop over all candidate

*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        
        int nSize = S.size();
        
        if(nSize < 3){
            return 0;
        }
        
        sort(S.begin(), S.end());
        
        int count = 0;
        
        for(int a = nSize - 1; a > 1; --a){
            int b = 0;
            int c = a - 1;
            
            while(b < c){
                if(S[b] + S[c] > S[a]){
                    count += (c - b);
                    --c;
                    
                }else{
                    ++b;                    
                }
  
            }
        }

        return count;
    }
};