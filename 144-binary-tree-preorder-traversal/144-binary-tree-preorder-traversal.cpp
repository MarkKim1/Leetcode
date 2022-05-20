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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        
        if(root == NULL){
            return result;
        }
        stk.push(root);
        while(!(stk.empty())){
            TreeNode *node = stk.top();
            result.push_back(node->val);
            stk.pop();
            if(node->right != NULL){
                stk.push(node->right);
            }
            if(node->left != NULL){
                stk.push(node->left);
            }
        }
        return result;
    }
};