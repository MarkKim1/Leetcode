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
    int preorderIndex;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        vector<bool> visited(preorder.size(),false);
        int in_place = 0;
        for(int i = 0; i <inorder.size(); i++){
            map[inorder[i]] = i;
        }
       return helper(preorder,inorder,0,preorder.size()-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int left, int right){
        if(left > right) return NULL;
        int root_value = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(root_value);
        
        root->left = helper(preorder,inorder,left,map[root_value]-1);
        root->right = helper(preorder,inorder,map[root_value]+1,right);
        return root;
    }
};