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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl = 0, hr = 0;
        TreeNode* a = root;
        TreeNode* b = root;
        while(a){
            hl++;
            a = a->left;
        }
        while(b){
            hr++;
            b = b->right;
        }
        return hl == hr ? (1 << hl) - 1 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};