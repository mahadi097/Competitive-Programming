# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        node_values = []
        
        def traverseBST(node: TreeNode) -> None:
            if node is None: return
            
            traverseBST(node.left)
            
            node_values.append(node.val)
            
            traverseBST(node.right)
        
        
        def constructBST(i: int, j: int) -> TreeNode:
            if i > j: return None
            
            mid = (i + j) // 2
            
            node_new = TreeNode(node_values[mid])
            
            node_new.left = constructBST(i, mid-1)
            node_new.right = constructBST(mid+1, j)

            return node_new
        
          
        traverseBST(root)
        
        return constructBST(0, len(node_values)-1)