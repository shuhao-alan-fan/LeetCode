# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.max_sum = -math.inf
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        
        

        def dfs(root):
            # max_sum = -math.inf
            if not root: return 0
            left = dfs(root.left)
            right = dfs(root.right)
            max_left = max(0,left)
            max_right = max(0,right)
            self.max_sum = max(self.max_sum, max_left+max_right+root.val)

            return root.val + max(max_left,max_right)

        dfs(root)

        return self.max_sum