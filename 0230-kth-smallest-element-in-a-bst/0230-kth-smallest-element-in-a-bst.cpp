/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = nullptr;
        inorder_dfs(cur,root,k);
        return cur->val;
    }
    
    void inorder_dfs(TreeNode*& cur, TreeNode* root, int& k){
        if(!root || cur) return;
        inorder_dfs(cur, root->left, k);
        if(--k == 0){
            cur = root;
            return;
        }
        inorder_dfs(cur,root->right, k);
    }
};