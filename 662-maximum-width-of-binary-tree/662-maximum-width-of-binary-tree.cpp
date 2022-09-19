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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long result = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            result = max(result,end-start+1);
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                long long count = q.front().second-start;
                q.pop();
                if(node->left){
                    q.push({node->left,count*2});
                }
                if(node->right){
                    q.push({node->right,count*2+1});
                }
            }
        }
        return result;
    }
};