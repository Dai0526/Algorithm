"""
69. Binary Tree Level Order Traversal
https://www.lintcode.com/problem/binary-tree-level-order-traversal/
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

Example 1:

Input：{1,2,3} Output：[[1],[2,3]]
Explanation：
  1
 / \\
2   3
it will be serialized {1,2,3}

Example 2:
Input：{1,#,2,3} Output：[[1],[2],[3]]
Explanation：
1
 \\
  2
 /
3
it will be serialized {1,#,2,3}
level order traversal

Challenge
1: Using only 1 queue to implement it.
2: Use BFS algorithm to do it.

"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


from collections import deque

class levelOrderTraversal:
    
    """
    @param root: A Tree
    @return: Level order a list of lists of integer

    idea is to use BFS:
    1. add root to Queue
    2. while Queue is not empty do following:
        a. for number of nodes int current queue
            1. pop top, and it to this level's list
            i. add its child
            ii. add its right child
        b. add this level's list to the result 


    """
    def levelOrder(self, root):
        # write your code here
        if root is None:
            return []
            
        queue = deque([root])
        output = []
        
        while queue:
            this_level = []
            size = len(queue) # attention, size is set, python is fine and c++ is a problem           
            for _ in range(size):
                node = queue.popleft()
                this_level.append(node.val)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)    

            output.append(this_level)
            
        return output
            
                
            