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
    int postorderIndex;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        postorderIndex = postorder.size()-1;
        return build(postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& postorder, int left, int right){
        if(left > right) return NULL;
        
        int rootValue = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootValue);
        root->right = build(postorder,map[rootValue]+1,right);
        root->left = build(postorder,left,map[rootValue]-1);
        return root;
    }
};