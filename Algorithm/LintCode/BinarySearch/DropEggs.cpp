/*
254. Drop Eggs
https://www.lintcode.com/problem/drop-eggs/
There is a building of n floors. If an egg drops from the k th floor or above, it will break. If it's dropped from any floor below, it will not break.
You're given two eggs, Find k while minimize the number of drops for the worst case. Return the number of drops in the worst case.

Example
Example 1:

Input: 100
Output: 14
Example 2:

Input: 10
Output: 4
Clarification
For n = 10, a naive way to find k is drop egg from 1st floor, 2nd floor ... kth floor. But in this worst case (k = 10), you have to drop 10 times.

Notice that you have two eggs, so you can drop at 4th, 7th & 9th floor, in the worst case (for example, k = 9) you have to drop 4 times.


思路 二分法 或者叫递增查找

不能单纯x2, 因为这样区间会越来越大。最合适的做法是找到一个合适的数值n，然后每次比之前一次做递减，这样能够保证投掷总数恒定为n
比如n = 10， 先从4开始，如果失败，挨个找123， 4-1-2-3 最差4次
              成功就跳3级，找7， 失败，找56， 4-7-5-6 最差4次
                成功就跳2级，找9， 失败，找9, 4-7-9-8 最差4次
如何找到这个4？逆向看是等差数列
所以可以用求和的方式，如果和大于n,则看上一次加了多少

while(sum < n){
    step += 1
    sum += step
}

既然是等差数列，用求和公式逆运算可得n

(k + 1)*k/2 >= n
k^2 + k - 2n >= 0 

 a = 1
 b = 1
 c = -2n

 k = -b + sqrt(b^2 - 4ac)   / 2a



*/
#include <math.h>
class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        long long thisDrop = 0;
        long long totalHeight = 0;
        
        while(totalHeight < n){
            
            thisDrop += 1;
            totalHeight += thisDrop;
            
        }
        
        
        return thisDrop;
    }
    
    int dropEggs2(int n) {
        //int a = 1;
        //int b = 1;
        //int c = -2 * n;
        //double k = (-b + sqrt(b*b - 4*a*c)) / (2*a);        
        double val = (-1 + sqrt(1 + 8.0 * n))/2;
        return static_cast<long long>(ceil(val));
    }
};