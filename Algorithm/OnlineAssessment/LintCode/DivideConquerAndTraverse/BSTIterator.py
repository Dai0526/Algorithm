"""
86. Binary Search Tree Iterator
https://www.lintcode.com/problem/binary-search-tree-iterator/
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.

Example 1

Input:  {10,1,11,#,6,#,12} Output:  [1, 6, 10, 11, 12]
Explanation:
The BST is look like this:
  10
  /\\
 1 11
  \\  \\
   6  12
You can return the inorder traversal of a BST [1, 6, 10, 11, 12]

Example 2
Input: {2,1,3} Output: [1,2,3]
Explanation:
The BST is look like this:
  2
 / \\
1   3
You can return the inorder traversal of a BST tree [1,2,3]

Challenge
Extra memory usage O(h), h is the height of the tree.
Super Star: Extra memory usage O(1)

Example of iterate a tree:
iterator = BSTIterator(root)
while iterator.hasNext():
    node = iterator.next()
    do something for node 


IDEA:

iterator ---> use stack

In Order Iterator -> find left first, then root, then right
How to find the next node? Find its sub right trees's the left most

Thus, the iterator will find the root.right, 
1. if exist, then keep going left
2. If it is null, 

经典BST模板， 加强记忆
"""


class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class BSTIterator:
    """
    @param: root: The root of binary tree.
    """

    def __init__(self, root):
        # do intialization if necessary
        self.stack = []
        while root != None:
            self.stack.append(root)
            root = root.left

    """
    @return: True if there has next node, or false
    """
    def hasNext(self):
        # write your code here
        return len(self.stack) > 0
                
    """
    @return: return next node
    """
    def next(self):
        # write your code here
        node = self.stack[-1]
        
        if node.right is not None:
            n = node.right
            while n != None:
                # note that when right exist, no pop, just push,  it is for trace back
                self.stack.append(n)
                n = n.left
        else:
            # right is non means the right most tree is to the leaf,
            # this sub tree is down, thus, trace back to the root of this sub tree
            #
            n = self.stack.pop()
            while self.stack and self.stack[-1].right == n:
                n = self.stack.pop()
                
        return node