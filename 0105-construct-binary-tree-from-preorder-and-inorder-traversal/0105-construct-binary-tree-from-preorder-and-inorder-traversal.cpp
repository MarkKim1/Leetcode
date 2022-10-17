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
    unordered_map<int,int> map;
    int preorderIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        return helper(preorder,inorder,0,preorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right) return NULL;
        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);
        
        root->left = helper(preorder,inorder,left,map[rootValue]-1);
        root->right = helper(preorder,inorder,map[rootValue]+1,right);
        return root;
    }
};