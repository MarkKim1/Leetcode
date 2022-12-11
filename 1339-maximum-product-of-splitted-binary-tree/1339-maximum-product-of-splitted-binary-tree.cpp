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
    int maxProduct(TreeNode* root) {
        int total = 0;
        gettotal(root,total);
        long result = 0;
        ans(root,total,result);
        
        return (int)(result % 1000000007);
    }
    int ans(TreeNode* root, int total,long& result){
        if(!root) return 0;
        int left = ans(root->left, total,result);
        int right = ans(root->right, total,result);
        int totalsum = left + right + root->val;
        long  totalproduct = (long)totalsum * (total-totalsum);
        result = max(result,totalproduct);
        return totalsum;
    }
    void gettotal(TreeNode* root, int& total){
        if(!root) return;
        total += root->val;
        gettotal(root->left, total);
        gettotal(root->right,total);
    }
};