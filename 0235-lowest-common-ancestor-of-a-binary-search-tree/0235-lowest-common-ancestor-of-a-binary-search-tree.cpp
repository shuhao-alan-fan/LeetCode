/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {    
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    // vector<TreeNode*> commonAncestor(TreeNode* root, TreeNode* p){
    //     stack<TreeNode*> s;
    //     vector<TreeNode*> v;
    //     bool flag = false;
    //     s.push(root);
    //     TreeNode* prev = root;
        
    //     while(!s.empty()){
            
    //         TreeNode* node = s.top();
    //         s.pop();
    //         if(node){
                
    //             if(node->val == p->val){
    //                 v.push_back(prev);
    //                 flag = true;
    //                 break;
    //             }
    //             else{
    //                 prev = node;
    //                 s.push(node->right);
    //                 s.push(node->left);
    //             }
    //         }
    //     }
    //     if (flag == true){
    //         return v;
    //     }
    //     return {};
    // }
};