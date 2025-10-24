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
    int result = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return result;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int leftnum = max(helper(root->left),0);
        int rightnum = max(helper(root->right),0);
        result = max(result, root->val + leftnum + rightnum);
        return root->val + max(leftnum,rightnum);
    }
};