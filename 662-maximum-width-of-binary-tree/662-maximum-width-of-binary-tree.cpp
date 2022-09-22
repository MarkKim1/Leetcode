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
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int result = INT_MIN;
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            result = max(result,end-start+1);
            for(int i = 0; i < size; i++){
                auto node = q.front().first;
                int count = q.front().second-start;
                q.pop();
                if(node->left){
                    q.push({node->left,(long long)count*2});
                }
                if(node->right){
                    q.push({node->right,(long long)count*2+1});
                }
            }
        }
        return result;
    }
};