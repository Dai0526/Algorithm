/*
https://leetcode.com/problems/majority-element-ii/
The idea is to get 2 nums with most count, then check if its count is greater than boundary 1/3

In order to achieve space of O(1)

for(n : nums)
1. n == num1, cnt1++
2. n == num2, cnt2++
3. cnt1 == 0, current not major number(or all number has same count) -> num1 = n, cnt1 = 1
4. cnt1 != 0 && cnt2 == 0, no second major number -> num2 = n, cnt2 = 1
5. ELSE: another number is found, reduce current candidates' weight-> --cnt1, --cnt2

After this loop, you will get 2 candidates, then loop over to get their real count and check

*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // 1/3 as majority, means there are at most two elements are majority
        int cnt1 = 0;
        int cnt2 = 0;
        
        int num1 = numeric_limits<int>::min();
        int num2 = numeric_limits<int>::min();
        
        for(int n : nums){
            
            if(num1 == n){
                ++cnt1;
            }else if(num2 == n){
                ++cnt2;
            }else if(cnt1 == 0){
                num1 = n;
                cnt1 = 1;
            }else if(cnt1 != 0 && cnt2 == 0){
                num2 = n;
                cnt2 = 1;
            }else{
                --cnt1;
                --cnt2;
            }
        }
        
        // get 2 possible candidate's real count
        cnt1 = 0;
        cnt2 = 0;
        for(int n : nums){
            if(n == num1){
                ++cnt1;
            }else if(n == num2){
                ++cnt2;
            }
        }
        vector<int> candidate;
        
        int bound = nums.size() / 3;
        if(cnt1 > bound){
            candidate.push_back(num1);
        }
 
        if(cnt2 > bound){
            candidate.push_back(num2);
        }
        
        return candidate;
    }
};