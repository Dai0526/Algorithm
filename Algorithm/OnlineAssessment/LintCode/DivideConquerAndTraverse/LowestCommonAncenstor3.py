"""
578. Lowest Common Ancestor III
https://www.lintcode.com/problem/lowest-common-ancestor-iii
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example1

Input: {4, 3, 7, #, #, 5, 6}

Explanation:
  4
 / \
3   7
   / \
  5   6

LCA(3, 5) = 4
LCA(5, 6) = 7
LCA(6, 7) = 7
LCA(5, 8) = null

Example2

Input: {1}, Output: LCA(1, 1) = 1
Explanation:
The tree is just a node, whose value is 1.

node A or node B may not exist in tree.
Each node has a different value

基本LCA思路
    # A,B 都在 root 为根的二叉树里, return lca(A,B)
    # 如果 A,B 都不在 root 为根的二叉树里, return None
    # 如果只有 A 在，return A
    # 如果只有 B 在，return B
对于本题
Furthermore, we can add more details to the return value to amke it more generic

    # A,B 都在 root 为根的二叉树里, return lca(A,B)
    # 如果 A,B 都不在 root 为根的二叉树里, return None
    # 如果只有 A 在，return has A, no B, A node
    # 如果只有 B 在，return no A, has B, B node
    # 最后做一个判断，如果AB有一个不在，就return None

"""

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        this.val = val
        this.left, this.right = None, None
"""


class LCA:

    """
    @param: root: The root of the binary tree.
    @param: A: A TreeNode
    @param: B: A TreeNode
    @return: Return the LCA of the two nodes.
    """
    def lowestCommonAncestor3(self, root, A, B):
        # write your code here
        has_a, has_b, lca_node = self.lcaHelper(root, A, B)    
        if has_a and has_b:
            return lca_node
        else:
            return None
        
        
    def lcaHelper(self, root, A, B):
        if root is None:
            return False, False, None
            
        has_left_a, has_left_b, left_node = self.lcaHelper(root.left, A, B)
        has_right_a, has_right_b, right_node = self.lcaHelper(root.right, A, B)
        
        # if one of them has A or B then set true correspondently
        has_a = has_left_a or has_right_a or root == A
        has_b = has_left_b or has_right_b or root == B
        
        # if A or B is root itself return root
        if root == A or root == B:
            return has_a, has_b, root

        # if both exist, return root
        if left_node is not None and right_node is not None:
            return has_a, has_b, root
        
        # if only left brunch, return left, else return right
        if left_node is not None:
            return has_a, has_b, left_node
        elif right_node is not None:
            return has_a, has_b, right_node
            
        return has_a, has_b, None