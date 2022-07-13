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
    
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* x = NULL;
        TreeNode* y = NULL;
        recover(root,prev,x,y);
        swap(x->val,y->val);
        
    }
    void recover(TreeNode* root,TreeNode*& prev,TreeNode*& x, TreeNode*& y){
        if(root == NULL) return;
        recover(root->left,prev,x,y);
        if(prev != NULL and root->val < prev->val){
            x = root;
            if(y == NULL){
                y = prev;
            }
        }
        prev = root;
        recover(root->right,prev,x,y);
    }
};