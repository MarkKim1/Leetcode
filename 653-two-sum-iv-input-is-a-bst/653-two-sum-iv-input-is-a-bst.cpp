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
    unordered_set<int>set;
    bool findTarget(TreeNode* root, int k) {
        if(!root->left and !root->right){
            return false;
        }
        return DFS(root, k);
    }
    bool DFS(TreeNode* root, int k){
        if(!root){
            return false;
        }
        if(set.find(k-root->val) != set.end()){
            return true;
        }
        set.insert(root->val);
        return DFS(root->left,k) || DFS(root->right,k);
    }
};