/*
Sort then two pointers moveing towards
*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = people.size() - 1;
        
        int count = 0;
        
        while(l <= r){
            if(people[l] + people[r] <= limit){
                ++l;
            }
            
            --r;
            ++count;
        }     
        
        return count;
    }
};