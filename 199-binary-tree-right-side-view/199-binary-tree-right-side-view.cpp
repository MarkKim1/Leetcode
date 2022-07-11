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
    int max_depth;
    vector<int> result;
    vector<int> rightSideView(TreeNode* root) {
        max_depth = 0;
        DFS(root,1);
        return result;
    }
    void DFS(TreeNode* root,int curr){
        if(root == NULL){
            return;
        }
        if(curr > max_depth){
            max_depth = curr;
            result.push_back(root->val);
        }
        DFS(root->right,curr+1);
        DFS(root->left,curr+1);
        
    }
};