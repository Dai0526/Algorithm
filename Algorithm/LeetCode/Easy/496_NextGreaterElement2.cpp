/*
https://leetcode.com/problems/next-greater-element-i/
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int s1 = nums1.size();
        vector<int> ans(s1, -1);
        
        int s2 = nums2.size();
        unordered_map<int, int> rec;
        for(int i = 0; i < s2; ++i){
            rec[nums2[i]] = i;
        }
        
        for(int i = 0; i < s1; ++i){
            for(int j = rec[nums1[i]]; j < s2; ++j){
                if(nums1[i] < nums2[j]){
                    ans[i] = nums2[j];
                    break;
                }    
            }
        }   
        return ans;
    }
};