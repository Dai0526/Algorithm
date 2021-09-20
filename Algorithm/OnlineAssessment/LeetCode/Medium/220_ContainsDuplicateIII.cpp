/*
Sliding window

*/
#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0 || nums.size() < 2){
            return false;
        }
        
        multimap<int, int> rec; // num, idx
        for(int i = 0; i < nums.size(); ++i){
            rec.insert({nums[i], i});
        }
        
        multimap<int, int>::iterator curr, next;
        for(curr = rec.begin(); curr != rec.end(); ++curr){
            
            next = curr;
            ++next;
            
            while(next != rec.end()){

                long long fst = (*curr).first;
                long long snd = (*next).first;
                            
                if(abs(fst - snd) > t){
                    break;
                }
                
                int fstIdx =  (*curr).second;
                int sndIdx =  (*next).second;
                
                if(abs(fstIdx - sndIdx) <= k){
                    return true;
                }
                ++next;
            }  
        }
        
        return false;
    }
};