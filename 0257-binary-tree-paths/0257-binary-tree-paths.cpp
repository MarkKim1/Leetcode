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
    vector<string> result;
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root, "");
        return result;
    }
    void helper(TreeNode* root, string path){
        if(!root) return;
        if(!root->left and !root->right){
            path += to_string(root->val);
            result.push_back(path);
        }
        helper(root->left, path + to_string(root->val) + "->");
        helper(root->right, path + to_string(root->val) + "->");
    }
};