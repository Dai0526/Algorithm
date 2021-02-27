/*
The problem of the 2-ptr approach is to justify the algorithm is valid

*/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        
        int areaMax = numeric_limits<int>::min();
        
        while(left < right){
            int area = min(height[left], height[right]) * (right - left);
            areaMax = max(areaMax, area);
            
            if(height[left] < height[right]){
                ++left;
            }else{
                --right;
            }
        }
        
        return areaMax;
    }
};