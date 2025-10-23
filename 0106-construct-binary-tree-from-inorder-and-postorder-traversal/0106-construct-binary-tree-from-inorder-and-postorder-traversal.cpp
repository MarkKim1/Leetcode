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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rootindex = postorder.size() - 1;
        return helper(inorder, postorder, 0, postorder.size() - 1, rootindex);
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int left, int right, int& rootindex){
        if(left > right) return NULL;
        int pivot = left;
        while(postorder[rootindex] != inorder[pivot]) pivot++;
        rootindex--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->right = helper(inorder,postorder,pivot + 1, right,rootindex);
        newNode->left = helper(inorder,postorder,left,pivot - 1, rootindex);
        return newNode;
    }
};