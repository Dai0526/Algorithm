
"""
616. Course Schedule II
https://www.lintcode.com/problem/course-schedule-ii
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: n = 2, prerequisites = [[1,0]] 
Output: [0,1]

Example 2:
Input: n = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]] 
Output: [0,1,2,3] or [0,2,1,3]

弃用计数，改用一个list来存储纪录
"""

from collections import deque

class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: the course order
    """
    def findOrder(self, numCourses, prerequisites):
        #init graph and degree
        graph = {i: [] for i in range(numCourses)}
        degree = [0 for i in range(numCourses)]
        
        # build graph
        for course, pre in prerequisites:
            graph[pre].append(course)
            degree[course] += 1
            
        my_queue = deque()
        course_path = []
        
        #push all 0 degree preRequests
        for i in range(numCourses):
            if degree[i] == 0:
                my_queue.append(i)
                           
        while my_queue:
            course = my_queue.popleft()
            course_path.append(course)
            
            for c in graph[course]:
                degree[c] -= 1
                if degree[c] == 0:
                    my_queue.append(c)
                     
        if len(course_path) == numCourses:
            return course_path
        
        
        return []