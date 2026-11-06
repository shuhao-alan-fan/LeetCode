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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        dfs(root,0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int depth, int& max_depth){
        if(!root) return;
        depth++;
        max_depth = max(depth, max_depth);
        dfs(root->left, depth, max_depth);
        dfs(root->right, depth, max_depth);
    }
};