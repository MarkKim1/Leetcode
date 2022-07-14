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
    void recoverTree(TreeNode* root) {
        TreeNode* node = root;
        TreeNode* pred = NULL;
        TreeNode* predecessor = NULL;
        TreeNode* x = NULL;
        TreeNode* y = NULL;
        while(node){
            if(node->left){
                predecessor = node->left;
                while(predecessor->right and predecessor->right != node){
                    predecessor = predecessor->right;
                }
                if(predecessor->right == NULL){
                    predecessor->right = node;
                    node = node->left;
                }else{
                    if(pred and node->val < pred->val){
                        y = node;
                        if(x == NULL) x = pred;
                    }
                    pred = node;
                    predecessor->right = NULL;
                    node = node->right;
                }
            }else{
                if(pred and node->val < pred->val){
                    y = node;
                    if(x == NULL) x = pred;
                }
                pred = node;
                node = node->right;
            }
        }
        swap(x->val,y->val);
    }
};