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
        for(int i = 0; i < inorder.size();i++){
            map[inorder[i]] = i;
        }
        return build(preorder,0,preorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int left, int right){
        if(left > right) return NULL;
        
        int rootValue = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootValue);
        root->left = build(preorder,left,map[rootValue]-1);
        root->right = build(preorder,map[rootValue] + 1,right);
        return root;
        // if(curr < preorder.size() and curr >= 0 and pivot >= 0 and pivot < preorder.size()){
        //     root = new TreeNode(inorder[map[preorder[curr]]]);
        //     pivot = map[preorder[curr]];
        //     curr++;
        //     build(root->left,inorder,preorder,pivot-1,seen);
        //     build(root->right,inorder,preorder,pivot+1,seen);
        // }else{
        //     return;
        // }
    }
};