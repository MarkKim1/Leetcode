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
    void flatten(TreeNode* root) {
        TreeNode* now = root;
        while(now){
            if(now->left){
                auto prev = now->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = now->right;
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
};