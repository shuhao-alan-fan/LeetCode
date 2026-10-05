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

        return dfs(root, 0);
    } 
    int dfs(TreeNode* root, int max_len){
        
        if(root){
            max_len += 1;
            return max(dfs(root->left,max_len),dfs(root->right,max_len));
        }
        return max_len;
    }
};