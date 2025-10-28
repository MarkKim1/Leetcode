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
    bool firstRootIsFound = false;
    int currpos = 0;
    int ans = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
            if(!firstRootIsFound){
                firstRootIsFound = true;
            }
            return 0;
        }
        kthSmallest(root->left,k);
        if(firstRootIsFound){
            currpos++;
            if(currpos == k) ans = root-> val;
        }
        kthSmallest(root->right,k);
        return ans;
    }
};