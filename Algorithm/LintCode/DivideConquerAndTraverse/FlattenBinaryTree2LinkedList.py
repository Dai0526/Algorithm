"""
453. Flatten Binary Tree to Linked Lis
https://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
Flatten a binary tree to a fake "linked list" in pre-order traversal.
Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example 1:

Input:{1,2,5,3,4,#,6} Output：{1,#,2,#,3,#,4,#,5,#,6}
Explanation：
     1
    / \\
   2   5
  / \\   \\
 3   4   6

1
 \\
  2
   \\
    3
     \\
      4
       \\
        5
         \\
          6
Example 2:

Input:{1} Output:{1}
Explanation：
         1
         1
Challenge
Do it in-place without any extra memory.

Notice
Don't forget to mark the left child of each node to null. 
Or you will get Time Limit Exceeded or Memory Limit Exceeded.


IDEA

Divid and Conquar
     1                   1             1
    / \\                / \\              2
   2   5      ->       2   5    ->          3
  / \\   \\             \\   \\               4
 3   4   6               3    6                 5
                          \\                      6
                           4         

*connect root.right to root.left
*then connect the last node of root.left to the first of root.right

"""


#Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None


class Faltten:
    """
    @param root: a TreeNode, the root of the binary tree
    @return: nothing

    """
    def flatten(self, root):
        # write your code here
        self.flattenHelper(root)
            
    def flattenHelper(self, root):
        if root is None:
            return
        
        left_last = self.flattenHelper(root.left)
        right_last = self.flattenHelper(root.right)
        
        if left_last is not None:
            left_last.right = root.right
            root.right = root.left
            root.left = None
        
        # note Important!!!
        # A or B or C in one line has sequence, check A first, then check B, at last check C
        # not the same in c++
        return right_last or left_last or root  