"""
480. Binary Tree Paths
https://www.lintcode.com/problem/binary-tree-paths/
Given a binary tree, return all root-to-leaf paths.

Example 1:
Input：{1,2,3,#,5}, Output：["1->2->5","1->3"]
Explanation：
   1
 /   \\
2     3
 \\
  5

Example 2:
Input：{1,2}, Output：["1->2"]
Explanation：
   1
 /   
2     
"""

#Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class binaryTreePaths:
    """
    @param root: the root of the binary tree
    @return: all root-to-leaf paths

    idea: 
    string concatenation costs memory and time, which is not a good practice, 
    thus, save result to a list first, then make path string and add to result.

    It's a practice to use ''.join(iteratable data structure), but value can only be string type

    Very typical divide and conquer problem, use two recursion to traversal
    left and right, then deal with the output

    """
    def binaryTreePaths(self, root):
        paths = self.treePathHelper(root)
        out = []
        
        for path in paths:
            rev = path
            rev.reverse()
            out.append('->'.join(rev))
        
        return out
        
        
    def treePathHelper(self, root):
        if root is None:
            return []   
        if root.right is None and root.left is None:
            return [[str(root.val)]]
            
        left_paths = self.treePathHelper(root.left)
        right_paths = self.treePathHelper(root.right)
        
        all_routes = left_paths + right_paths
        
        for i in all_routes:
            i.append(str(root.val))

        return all_routes