/*
https://leetcode.com/problems/nth-digit/
1. A brute force solution is to make a string, then find nth character, time exceed exception

2. Find pattern
*/

class Solution {
public:
    int findNthDigit(int n) {
        
        // 初始化一位数的个数有9个，从1开始
        long long len = 1, cnt = 9, start = 1;
        while (n > len * cnt) {
            // 以此类推二位数的个数有90个，从10开始
            n -= len * cnt;
            ++len;
            cnt *= 10;
            start *= 10;
        }
        // 找到第n位在整数start当中
        start += (n - 1) / len;
        string t = to_string(start);
        return t[(n - 1) % len] - '0';
        
    }
};