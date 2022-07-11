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
    vector<vector<int>> result;
    vector<vector<int>> findLeaves(TreeNode* root) {
        this->result.clear();
        DFS(root);
        return result;
    }
    int DFS(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        int leftHeight = DFS(root->left);
        int rightHeight = DFS(root->right);
        int currHeight = max(leftHeight,rightHeight)+1;
        if(result.size() == currHeight){
            result.push_back({});
        }
        result[currHeight].push_back(root->val);
        return currHeight;
    }
};