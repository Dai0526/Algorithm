/*
two ptr to find intersection

Then move and count, once meet itslef, valide length


*/

#include <vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
     
        // take mod for fast indexing if k > n
        for(int &num : nums){
            num = num % n;
        }
        
        // start from any index can reach a cycle, thus, check each idx
        for(int i = 0; i < n; ++i){
            if (nums[i] == 0) {
				continue;
			}
                     
            int slow = i;
            int fast = i;
            int direction = nums[i] > 0 ? 1 : -1;
            while(true){

                fast = getIdx(fast, nums[fast], n);
                if(nums[fast] * direction <= 0){
                     break; // back and forth, not a cycle
                }
                
                // fast go two moves per time
                fast = getIdx(fast, nums[fast], n);
                if(nums[fast] * direction <= 0){
                     break; // back and forth, not a cycle
                }
                
                slow = getIdx(slow, nums[slow], n); // no need to check the sign of i, cause j has passed this point
				if (fast == slow) {
					return true; // there is a cycle
				}
            }
            
        }
        
        return false;
    }
    
private:
    int getIdx(int idx, int nMove, int size) {
		return (idx + nMove + size) % size;
	}
};