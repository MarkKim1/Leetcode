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
    vector<vector<int>> result;
    vector<int> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum);
        return result;
    }
    void preorder(TreeNode* root,int targetSum){
        if(root == NULL) return;
        ans.push_back(root->val);
        targetSum-=root->val;
        preorder(root->left,targetSum);
        preorder(root->right,targetSum);
        if(targetSum == 0 and root->left == NULL and root->right == NULL){
            result.push_back(ans);
        }
        targetSum+=root->val;
        ans.pop_back();
    }
};