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
    int res;
    int maxPathSum(TreeNode* root) {
        res = root->val;
        DFS(root);
        return res;
    }
    int DFS(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftMax = max(DFS(root->left),0);
        int rightMax = max(DFS(root->right),0);
        res = max(res,root->val + leftMax + rightMax);
        return root->val + max(leftMax,rightMax);
    }
};