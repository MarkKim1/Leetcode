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
    unordered_map<int,int>map;
    int preorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        preorderIndex = 0;
        return build(preorder,0,preorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int left, int right){
        if(left > right) return NULL;
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        root->left = build(preorder,left,map[rootValue]-1);
        root->right = build(preorder,map[rootValue]+1,right);
        return root;
    }
};