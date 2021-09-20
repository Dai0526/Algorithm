/*
https://leetcode.com/problems/intersection-of-two-arrays/
Naive intersection, don't think about it too much.
Ask for calrification.

Use 2 set to remove duplicated. Then compare
time O(m + n)
space O(m + n)
*/

#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection_set(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> intersection;
        
        // we can work on smaller set for better performance
        for(const int n : set1){
            if(set2.find(n) == set2.end()){
                continue;
            }
            
            intersection.push_back(n);
        }
        
        return intersection;
    }
    
    // follow up - if sorted, make it O(n) and space O(1)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
     
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        int idx1 = 0;
        int idx2 = 0;
        
        vector<int> intersection;
        
        while(idx1 < l1 && idx2 < l2){
            int val1 = nums1[idx1];
            int val2 = nums2[idx2];
            
            if(val1 == val2){
                intersection.push_back(val1);
                
                // remove duplicated
                while(idx1 < l1 && val1 == nums1[idx1]){
                    ++idx1;
                }
                while(idx2 < l2 && val2 == nums2[idx2]){
                    ++idx2;
                }
            }else if(val1 > val2){
                ++idx2;
            }else{
                ++idx1;
            }
        }
        
        return intersection;
    }
    
};