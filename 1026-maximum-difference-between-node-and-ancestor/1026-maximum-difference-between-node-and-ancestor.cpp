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
    int maxAncestorDiff(TreeNode* root) {
        int ans = INT_MIN;
        vector<int> compute;
        DFS(root,compute,ans);
        return ans;
    }
    void DFS(TreeNode* root, vector<int>& compute, int& ans){
        if(!root) return;
        if(!compute.empty()){
            for(int i = 0; i < compute.size(); i++){
                ans = max(ans,abs(root->val - compute[i]));
            }
        }
        compute.push_back(root->val);
        DFS(root->left, compute, ans);
        DFS(root->right, compute, ans);
        compute.pop_back();
    }
};