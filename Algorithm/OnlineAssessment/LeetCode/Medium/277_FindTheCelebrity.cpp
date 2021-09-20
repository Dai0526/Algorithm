/* 
https://leetcode.com/problems/find-the-celebrity/
Brute Force is okay, but we can do logical induction

a. start with candidate 0
b. iterate all numbers to see if 0 know others,
        i. if 0 not know a number, e.g. 0 not know 2
            it proves 0 might be a celebrity, but 2 must not be a celebrity
        ii. if 0 know this number, e.g. 0 know 3,
            then 0 must not be celebrity, and take 3 as the candidate
    keep doing for the new candidate.

c. the candidate is not promising, it only shows candidate doesn't know 
    numbers after itself. 
    Thus, do a check fpr this node.


The knows API is defined for you.
      bool knows(int a, int b); 
*/



class Solution {

private:
    // The knows API is defined for you. bool knows(int a, int b); 
    bool knows(int a, int b){
        return true; // dummy one for compile.
    }

public:
    
    int findCelebrity(int n) {
        int candidate = 0;
        
        for(int i = 0; i < n; ++i){
            if(knows(candidate, i)){
                candidate = i;
            }
        }
        
        // check the given possible candidate
        for(int i = 0; i < n; ++i){
            if(i == candidate){
                continue;
            }
            
            if(knows(candidate, i) || !knows(i, candidate)){
                // no celebrity
                return -1;
            }
        }
        
        return candidate;
        
    }
    
    //brute force
    int findCelebrity_brute(int n) {
        for(int i = 0; i < n; ++i){
            bool isCelebrity = true;
            for(int j = 0; j < n; ++j){
                if(i == j){
                    //skip itslef
                    continue;
                }
                // if i know j, or j doesn't know i, means it is not
                if(knows(i,j) || !knows(j,i)){
                    isCelebrity = false;
                    break;
                }
            }
            
            if(isCelebrity){
                return i;
            }
        } 
        return -1;
    }
};