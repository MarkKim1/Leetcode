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
    long long result = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* root = q.front();
                helper(root,targetSum,0);
                q.pop();
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
            }
        }
        return result;
    }
    void helper(TreeNode* root, int targetSum, long long curr){
        if(!root){
            return;
        }
        if(curr + root->val == targetSum){
            result+=1;
        }
        helper(root->left,targetSum,curr + root->val);
        helper(root->right,targetSum,curr + root->val);
    }
};