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
    int answer;
    int longestUnivaluePath(TreeNode* root) {
        answer = 0;
        DFS(root);
        return answer;
    }
    int DFS(TreeNode* root){
        if(root == NULL) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        int arrowLeft = 0,arrowRight = 0;
        if(root->left != NULL and root->left->val == root->val){
            arrowLeft = left+1;
        }
        if(root->right != NULL and root->right->val == root->val){
            arrowRight = right+1;
        }
        answer = max(answer,arrowLeft + arrowRight);
        return max(arrowLeft,arrowRight);
    }
};