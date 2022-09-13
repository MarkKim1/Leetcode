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
    priority_queue<int,vector<int>,greater<>> pq;
    int kthSmallest(TreeNode* root, int k) {
        preorder(root);
        for(int i = 1; i < k; i++){
            pq.pop();
        }
        return pq.top();
    }
    void preorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        pq.push(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};