"""
612. K Closest Points
https://www.lintcode.com/problem/k-closest-points
Given some points and an origin point in two-dimensional space, find k points which are nearest to the origin.
Return these points sorted by distance, if they are same in distance, sorted by the x-axis, and if they are same in the x-axis, sorted by y-axis.

Example

Input: points = [[4,6],[4,7],[4,4],[2,5],[1,1]], origin = [0, 0], k = 3 
Output: [[1,1],[2,5],[4,4]]

Input: points = [[0,0],[0,9]], origin = [3, 1], k = 1
Output: [[0,0]]

"""


class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b

import math
import heapq
"""
heapq in python is a min heap, here we use a trick to give a negative value to 
simulate a max heap.
"""
class Solution:
    """
    @param points: a list of points
    @param origin: a point
    @param k: An integer
    @return: the k closest points
    """
    def kClosest(self, points, origin, k):
        min_heap = []
        for pt in points:
            distance = self.getDistance(pt, origin)
            heapq.heappush(min_heap, (-distance, -pt.x, -pt.y))
            
            # if more than k, remove the max one
            if len(min_heap) > k:
                heapq.heappop(min_heap)
                
        result = []
        while min_heap:
            _, x, y = heapq.heappop(min_heap)
            result.append(Point(-x, -y))
        
        result.reverse()
        return result
        
    def kClosest_weak(self, points, origin, k):
        # It's ok, but not recommend
        # 1. slower 2. not expected
        sorted_pt = sorted(points, key = lambda pt : (self.getDistance(pt, origin), pt.x, pt.y))
        
        return sorted_pt[:k]
        
        
    def getDistance(self, point, origin):
        
        dx = point.x - origin.x
        dy = point.y - origin.y
        
        return math.sqrt(dx * dx + dy * dy)
