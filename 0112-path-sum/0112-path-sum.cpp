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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        int result = root->val;
        if(!root->left and !root->right and result == targetSum) return true;
        return helper(root->left, targetSum, result) || helper(root->right, targetSum, result);
    }
    bool helper(TreeNode* root, int targetSum, int result){
        if(!root) return false;
        result += root->val;
        if(!root->left and !root->right){
            if(result == targetSum) return true;
            return false;
        }
        return helper(root->left, targetSum, result) || helper(root->right, targetSum, result);
    }
};