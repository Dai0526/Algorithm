#include <vector>

using namespace std;

class Solution {
public:

    bool kLengthApart(vector<int>& nums, int k) {
         
        int lastOneIdx = -1E5;
        
        for(int i = 0; i < nums.size(); ++i){
            
            if(nums[i] == 1){
                int dist = i - lastOneIdx - 1;
                
                if(dist < k){
                    return false;
                }
                
                lastOneIdx = i;
            }       
        }

        return true;        
    }
};