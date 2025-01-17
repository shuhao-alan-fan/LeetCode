class Solution {
public:
    int ans = 0;
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return ans++;
    }
    void dfs(TreeNode* root, int local_max){
        if(!root){
            return ;
        }
        if(root->val >= local_max){
            local_max = root ->val;
            ans ++;
        }
        dfs(root->left, local_max);
        dfs(root->right,local_max);
        return;
    }
};