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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<TreeNode*> p;
        vector<TreeNode*> v;
        vector<vector<int>> ans;
        // ans.push_back({root->val});
        v.push_back(root);
        while(!v.empty()){
            p = v;
            v.clear();
            vector<int> temp;

            for(auto& i:p){
                if(i){
                    temp.push_back(i->val);
                }
                if(i->left){
                    v.push_back(i->left);
                }
                if(i->right){
                    v.push_back(i->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    
};