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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> sub;
        helper(ans,sub,root,targetSum);
        return ans;
    }
    void helper(vector<vector<int>>& ans, vector<int>& sub, TreeNode* root, int targetSum){
        if(!root) return;
        sub.push_back(root->val);
        helper(ans,sub,root->left,targetSum-root->val);
        helper(ans,sub,root->right,targetSum-root->val);
        if(targetSum-root->val == 0 and !root->left and !root->right){
            ans.push_back(sub);
        }
        sub.pop_back();
    }
};