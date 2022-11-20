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
    unordered_map<int,int> map;
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for(int i = 0; i < nodes.size(); i++){
            map[nodes[i]->val] = i;
        }
        return helper(root);
        
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return NULL;
        TreeNode* left_root = helper(root->left);
        TreeNode* right_root = helper(root->right);
        
        if(map.find(root->val) != map.end()){
            return root;
        }
        if(left_root and right_root){
            return root;
        }
        return (left_root != nullptr) ? left_root : right_root;
    }
};