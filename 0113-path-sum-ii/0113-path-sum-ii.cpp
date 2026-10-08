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
        if(!root) return {};
        vector<vector<int>> ans;

        dfs(0,targetSum, root,{}, ans);
        return ans;
    }
    void dfs(int sum, int& targetSum, TreeNode* cur, vector<int> path, vector<vector<int>>& ans){
        if(!cur) return;
        sum += cur->val;
        path.push_back(cur->val);
        if(sum == targetSum){
            if(!cur->left && !cur->right){
                ans.push_back(path);
                return;
            }
        }
       
        dfs(sum, targetSum, cur->left, path, ans);
        dfs(sum, targetSum, cur->right, path, ans);

        return;
    }
};