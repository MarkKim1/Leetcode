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
    int count = 0;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        result.push_back(root->val);
        helper(root,0,result);
        return result;
    }
    void helper(TreeNode* root, int curr, vector<int>& result){
        if(root == NULL) return;
        if(curr > count){
            result.push_back(root->val);
            count = curr;
        }
        helper(root->right,curr+1,result);
        helper(root->left,curr+1,result);
    }
};