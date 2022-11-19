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
    int count = 0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = helper(root,p,q);
        return count == 2 ? ans : NULL;
    }
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }
        TreeNode* left_root = helper(root->left,p,q);
        TreeNode* right_root = helper(root->right,p,q);
        if(root->val == p->val || root->val == q->val){
            count++;
            return root;
        }
        if(left_root and right_root){
            return root;
        }
        return left_root != NULL ? left_root : right_root;
    }
};