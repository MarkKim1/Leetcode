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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0,0);
    }
    int helper(TreeNode* root, int num,int depth){
        if(!root) return 0;
        if(!root->left and !root->right){
            return num * 10 + root->val;
        }
        int leftnum = helper(root->left, num * 10 + root->val, depth + 1);
        int rightnum = helper(root->right, num * 10 + root->val, depth + 1);
        return leftnum + rightnum;
    }
};