# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        if root is None:
            return False
        elif root.left is None and root.right is None:
            return root.val == targetSum
        return self.hasPathSum(root.left, targetSum-root.val) or self.hasPathSum(root.right,targetSum-root.val)