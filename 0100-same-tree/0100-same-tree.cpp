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
    bool flag = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        //base case
        if(p != nullptr && q != nullptr && p->val != q->val) return false;
        if(p == nullptr && q != nullptr) return false;
        if(q == nullptr && p != nullptr) return false;
        if(q == nullptr && p == nullptr) return true;
        flag = isSameTree(p->left, q->left);
        if(flag == true){
            flag = isSameTree(p->right,q->right);
        }
        
        return flag;
    }
};