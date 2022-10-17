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
    unordered_map<long,int> map;
    int result = 0;
    int pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0);
        return result;
    }
    void helper(TreeNode* root, int targetSum, long curr){
        if(!root){
            return;
        }
        long sum = curr+root->val;
        if(sum == targetSum){
            result+=1;
        }
        if(map.find(sum-targetSum) != map.end()){
            result+=map[sum-targetSum];
        }
        map[sum]++;
        helper(root->left,targetSum,curr + root->val);
        helper(root->right,targetSum,curr+root->val);
        map[sum]--;
    }
};