/*
57. 3Sum
https://www.lintcode.com/problem/3sum/
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Example 1:
Input:[2,7,11,15], Output:[]

Example 2:
Input:[-1,0,1,2,-1,-4], Output:	[[-1, 0, 1],[-1, -1, 2]]

Notice
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.


思路：
for loop 遍历每一个数，以该数为target，转换成2sum的思路求解
要注意的地方是去重：
1. 对于每一个数，和前一个数作比较，如果相同则continue到下一个数
2. 对于每一组2sum, left 和 right 也要检查一直到不同为止，再进行下一个2sum判断

*/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        
        int nSize = numbers.size();
        vector<vector<int>> out;
        
        std::sort(numbers.begin(), numbers.end());
        
        for(int i = 0; i < nSize - 2; ++i){
            
            if(i > 0 && numbers[i] == numbers[i-1]){
                continue;
            }
            
            int target = -numbers[i];
            
            int left = i + 1;
            int right = nSize - 1;
            while(left < right){
                int temp = numbers[left] + numbers[right];
                
                if(temp == target){
                    vector<int> candidate(3);
                    candidate[0] = numbers[i];
                    candidate[1] = numbers[left];
                    candidate[2] = numbers[right];
                    
                    out.push_back(candidate);
                    
                    // move until unique pair
                    while(left < right && numbers[left] == numbers[left + 1]){
                        ++left;
                    }
                    
                    while(left < right && numbers[right] == numbers[right - 1]){
                        --right;
                    }
                    
                    ++left;
                    --right;
                    
                    
                }else if(temp > target){
                    --right;
                }else{
                    ++left;
                }
            }

        }
        
        
        return out;
    }
};