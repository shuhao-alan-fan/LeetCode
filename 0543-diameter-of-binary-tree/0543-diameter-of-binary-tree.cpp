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
    //left depth + right depth
    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        
        dfs(root,max_len);
        return max_len;
    }

    int dfs(TreeNode* root, int &max_len){
        if(root == nullptr) return 0;
        int left = dfs(root->left, max_len);
        int right = dfs(root->right, max_len);
        max_len = max(left + right, max_len); 
        return 1 + max(left,right);
    }
};