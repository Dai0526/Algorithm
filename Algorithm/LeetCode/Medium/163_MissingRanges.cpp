/*
https://leetcode.com/problems/missing-ranges/
divide to 3 parts

lower bound | mid | upper bound

Take care about int boundry, thus convert to long.

*/

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> ranges;
        
        long llower = (long)lower;
        long lupper = (long)upper;
        
        if(n < 1){
            ranges.push_back(getRange(lower, upper));
            return ranges;
        }
        
        // handle head
        if(nums[0] > lower){
            ranges.push_back(getRange(lower, (long)nums[0] - 1));
        }

        // handle in between
        for(int i = 1; i < n; ++i){
            if((long)nums[i] - (long)nums[i - 1] < 2){
                continue;
            }
            ranges.push_back(getRange((long)nums[i - 1] + 1, (long)nums[i] - 1));
        }
        
        // handle end
        if(nums[n - 1] < upper){
            ranges.push_back(getRange((long)nums[n - 1] + 1, upper));
        }
        
        return ranges;
        
    }
    
    
    string getRange(long pre, long curr){
        if(curr == pre){
            return to_string(pre);
        }
        
        //greater than 2
        stringstream ss;
        ss << pre << "->" << curr;
        return ss.str();
    }
};