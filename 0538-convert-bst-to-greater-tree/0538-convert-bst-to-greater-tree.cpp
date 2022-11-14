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
    int curr = 0;
    TreeNode* convertBST(TreeNode* root) {
        recur(root);
        return root;
    }
    void recur(TreeNode* root){
        if(!root){
            return;
        }
        recur(root->right);
        curr+=root->val;
        root->val = curr;
        recur(root->left);
        
    }
};