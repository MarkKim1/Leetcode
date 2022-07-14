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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> result;
        if(root){
            result.push_back(root->val);
            getBounds(root->left,result,true,false);
            getBounds(root->right,result,false,true);
        }
        return result;
    }
    void getBounds(TreeNode* node, vector<int>& result, bool lb, bool rb){
        if(node == NULL) return;
        if(lb) result.push_back(node->val);
        if(!lb and !rb and node->left == NULL and node->right == NULL) result.push_back(node->val);
        getBounds(node->left,result,lb,rb and node->right == NULL);
        getBounds(node->right,result,lb and node->left == NULL,rb);
        if(rb) result.push_back(node->val);
    }
};