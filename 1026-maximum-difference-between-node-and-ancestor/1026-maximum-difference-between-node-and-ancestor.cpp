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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,INT_MIN,INT_MAX);
    }
    int helper(TreeNode* root,int currMax, int currMin){
        if(!root){
            return currMax - currMin;
        }
        currMax = max(currMax, root->val);
        currMin = min(currMin, root->val);
        int left = helper(root->left,currMax,currMin);
        int right = helper(root->right,currMax, currMin);
        return max(left,right);
    }
};