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
        TreeNode* previous = NULL, *pred = NULL,*x = NULL,*y = NULL;
        while(root){
            if(root->left){
                pred = root->left;
                while(pred->right and pred->right != root){
                    pred = pred->right;
                }
                if(pred->right != root){
                    pred->right = root;
                    root = root->left;
                }else{
                    if(previous != NULL and previous->val > root->val){
                        y = root;
                        if(x == NULL) x = previous;
                    }
                    previous = root;
                    pred->right = NULL;
                    root = root->right;
                }
            }else{
                if(previous != NULL and previous->val > root->val){
                        y = root;
                        if(x == NULL) x = previous;
                    }
                previous = root;
                root = root->right;
            }
        }
        swap(x->val,y->val);
    }
};