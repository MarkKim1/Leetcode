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
    
    bool ans = true;
    int helper(TreeNode *curr){
        if(curr== NULL) return -1;
        if(!ans) return 0;
           int curr_left = helper(curr->left);
           int curr_right = helper(curr->right);
            if(abs(curr_left-curr_right) > 1){
                return ans = false;
            }
         return 1 + max(curr_left,curr_right);   
    }
    
    bool isBalanced(TreeNode* root) {
        TreeNode *curr = root;
        int result = helper(curr);
        return ans;
        
    }
};