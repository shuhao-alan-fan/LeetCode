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
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(0, 0, inorder.size(), preorder, inorder);
    }
    TreeNode* helper(int preB, int inB, int inE, vector<int>& preorder, vector<int>& inorder){
        if(preB > preorder.size() - 1 || inB > inorder.size() - 1){
            cout<<"error"<<endl;
            return nullptr;
        } 
        cout<<preB<<endl;
        TreeNode* root = new TreeNode(preorder[preB]);
        int mid = -1;
        for(int i = inB; i<inE; i++){
            if (preorder[preB] == inorder[i]){
                mid = i;
                break;
            }
        }
        if(mid == -1){
            cout<<"mid not found";
            return nullptr;
        }
        root->left = helper(preB+1, inB, mid, preorder, inorder);
        root->right = helper(preB + mid - inB +1, mid + 1, inE, preorder, inorder);
        return root;
    }
};