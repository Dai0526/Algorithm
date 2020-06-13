"""
875. Koko Eating Bananas
https://leetcode.com/problems/koko-eating-bananas/

Koko loves to eat bananas.  
There are N piles of bananas, the i-th pile has piles[i] bananas.  
The guards have gone and will come back in H hours.
Koko can decide her bananas-per-hour eating speed of K.  
Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  
If the pile has less than K bananas, she eats all of them instead, 
and won't eat any more bananas during this hour.

Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer K such that she can eat all the bananas within H hours.

Example:
Input: piles = [3,6,7,11], H = 8 Output: 4
Input: piles = [30,11,23,4,20], H = 5 Output: 30
Input: piles = [30,11,23,4,20], H = 6 Output: 23

Note:
1 <= piles.length <= 10^4
piles.length <= H <= 10^9
1 <= piles[i] <= 10^9
"""


"""
二分法，对结果进行二分
"""

from typing import List

class Solution:
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        #bounary for k is 1 to 10^9
        left, right = 1, max(piles)
        while left < right:
            mid = left + (right - left) // 2
            hour = self.getTime(mid, piles)
            
            if hour > H:
                left = mid + 1
            else:
                right = mid
        
        return right
            
            
    
    def getTime(self, speed: int, piles: List[int]) -> int:
        time = 0
        for p in piles:
            if p % speed == 0:
                time += p // speed
            elif p < speed:
                time += 1    
            else:
                time += (p // speed) + 1
        
        return time