/*
685. First Unique Number in Data Stream
中文English
Given a continuous stream of data, write a function that returns the first unique number (including the last number) when the terminating number arrives. If the unique number is not found, return -1.

Example1
Input: 
[1, 2, 2, 1, 3, 4, 4, 5, 6]
5
Output: 3

Example2
Input: 
[1, 2, 2, 1, 3, 4, 4, 5, 6]
7
Output: -1

Example3
Input: 
[1, 2, 2, 1, 3, 4]
3
Output: 3

method的解法，用一个map记录出现次数即可，
在2中需要设计一个class的话，则可以考虑用hasmap加上linkedList的操作

*/


#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    /**
     * @param nums: a continuous stream of numbers
     * @param number: a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> &nums, int number) {
        // Write your code here
        
        int nSize = nums.size();
        map<int, int> counter;
        bool hasTerminator = false;
        
        for(int i = 0; i < nSize; ++i){
            
            int curr = nums[i];
            
            if(counter.find(curr) == counter.end()){
                counter[curr] = 1;
            }else{
                ++counter[curr];
            }
            
            
            if(curr == number){
                hasTerminator = true;
                break;
            }
        }
        
        //check if there is a break
        if(!hasTerminator){
            return -1;
        }
        
        for(int data : nums){
            if(counter[data] == 1){
                return data;
            }
            if(data == number){
                break;
            }
        }
        
        return -1;
        
    }
};