"""
https://www.lintcode.com/problem/minimum-subtree/description
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example

Input: {1,-5,2,1,2,-4,-5}
Output: 1
The tree is look like this:
     1
   /   \\
 -5     2
 / \\   /  \\
1   2 -4  -5 
The sum of whole tree is minimum, so return the root.

Example 
Input: {1}
Output: 1
Explanation:
The tree is look like this:
   1
There is one and only one subtree in the tree. So we return 1.
Notice
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.
"""



from collections import deque
import sys
import time

#Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

    def print_tree_inorder(self, root):
        if root is None:
            return []
        
        queue = deque([root])
        result = []

        while queue:
            level = []

            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                level.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

            result += level
        
        print(result)



class MinimumSubtree:
    """
    @param root: the root of binary tree
    @return: the root of the minimum subtree
    """
    def findSubtree(self, root):
    
        # use muliple return values to avoid global variable
        _, subtree, _ = self.GetTreeSum(root)

        return subtree

    def GetTreeSum(self, root):
        # base case, if nullptr, return 0
        if root is None:
            return sys.maxsize, None, 0

        # do left, do right, make sum
        left_min, left_subtree, left_sum = self.GetTreeSum(root.left)
        right_min, right_subtree, right_sum = self.GetTreeSum(root.right)
        root_weight = left_sum + right_sum + root.val

        # if less weight found, assgin current node as root of the subtree
        min_val = min(left_min, right_min, root_weight)
        if left_min == min_val:
            return left_min, left_subtree, root_weight
        if right_min == min_val:
            return right_min, right_subtree, root_weight
        
        return root_weight, root, root_weight


    def findSubtreeGolbal(self, root):
        # write your code here
        self.min_weight = sys.maxsize
        self.subtree = None
        
        # recursivly divide and conquar
        self.GetTreeSumGolbal(root)

        return self.subtree

    def GetTreeSumGolbal(self, root):
        # base case, if nullptr, return 0
        if root is None:
            return 0

        # do left, do right, make sum
        left = self.GetTreeSum(root.left)
        right = self.GetTreeSum(root.right)
        root_weight = left + right + root.val

        # if less weight found, assgin current node as root of the subtree
        if root_weight < self.min_weight:
            self.min_weight = root_weight
            self.subtree = root

        return root_weight

# {1,-5,2,1,2,-4,-5}
root = TreeNode(1)
root.left = TreeNode(-5)
root.right = TreeNode(2)
root.left.left = TreeNode(1)
root.left.right = TreeNode(2)
root.right.left = TreeNode(-4)
root.right.right = TreeNode(-5)

root.print_tree_inorder(root)

test = MinimumSubtree()
start = time.time()
for i in range (10**6):
    subtree = test.findSubtree(root)
end = time.time()
print("MinimumSubtree takes {} mSec.".format(end - start))

root.print_tree_inorder(subtree)