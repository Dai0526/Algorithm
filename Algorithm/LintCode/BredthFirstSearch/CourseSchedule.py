"""
615. Course Schedule
https://www.lintcode.com/problem/course-schedule/
There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1
Input: n = 2, prerequisites = [[1,0]]
Output: true

Example 2:
Input: n = 2, prerequisites = [[1,0],[0,1]] 
Output: false
"""

from collections import deque

class Solution:
    """
    @param: numCourses: a total of n courses
    @param: prerequisites: a list of prerequisite pairs
    @return: true if can finish all courses or false
    """
    def canFinish(self, numCourses, prerequisites):
        
        graph = {i : [] for i in range(numCourses)} # key is prerequisites, value is a list of next course it can take after prerequisites
        degree = [0 for i in range(numCourses)]
        
        # build graph
        for li in prerequisites:
            course = li[0]
            pre = li[1]
            
            graph[pre].append(course)
            degree[course] += 1
        
        my_queue = deque()
        
        #push all zero degree vertext(class) into my_queue
        for course in range(len(degree)):
            if degree[course] == 0:
                my_queue.append(course)
                
        avil_course = 0
        # do a topological sort   
        while my_queue:
            
            pre = my_queue.popleft()
            avil_course += 1
            for course in graph[pre]:
                degree[course] -= 1
                if degree[course] == 0:
                    my_queue.append(course)
                    
        return (avil_course == numCourses)