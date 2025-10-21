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
    vector<int> leftvec;
    vector<int> rightvec;
    bool isSymmetric(TreeNode* root) {
        leftHelper(root->left);
        rightHelper(root->right);
        if(leftvec.size() != rightvec.size()) return false;
        for(int i = 0; i < leftvec.size(); i++){
            if(leftvec[i] != rightvec[i]) return false;
        }
        return true;
    }
    void leftHelper(TreeNode* root){
        if(!root){
            leftvec.push_back(1001);
            return;
        }
        leftHelper(root->left);
        leftHelper(root->right);
        leftvec.push_back(root->val);
    }
    void rightHelper(TreeNode* root){
        if(!root) {
            rightvec.push_back(1001);
            return;
        }
        rightHelper(root->right);
        rightHelper(root->left);
        rightvec.push_back(root->val);
    }
};