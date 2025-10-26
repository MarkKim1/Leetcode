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
    int depth = -1;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result,0);
        return result;
    }
    void helper(TreeNode* root, vector<int>& result, int currDepth){
        if(!root) return;
        if(currDepth > depth){
            result.push_back(root->val);
            depth = currDepth;
        }
        helper(root->right, result, currDepth + 1);
        helper(root->left, result,currDepth + 1);
    }
};