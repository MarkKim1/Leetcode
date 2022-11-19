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
        if(!root) return NULL;
        
        if(root->val == p->val || root->val == q->val){
            return root;
        }
        TreeNode* left_root = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_root = lowestCommonAncestor(root->right,p,q);
        if(left_root && right_root){
            return root;
        }
        return (left_root != NULL) ? left_root : right_root;
    }
};