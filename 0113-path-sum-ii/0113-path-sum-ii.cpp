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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, ans, path, targetSum);
        return ans;
    }

    void dfs(TreeNode* root,vector<vector<int>>& ans, vector<int>& path, int remain){
        if(!root) return;
        remain -= root->val;
        path.push_back(root->val);
        if(remain == 0 && !root->left && !root->right){
            ans.push_back(path);
        }
        else{
            dfs(root->left, ans, path, remain);
            dfs(root->right, ans, path, remain);
        }
        path.pop_back();
    }
};