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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        map<int,vector<int>> map;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root));
        
        while(!q.empty()){
            int temp = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();
            map[temp].emplace_back(node->val);
            if(node->left){
                q.emplace(make_pair(temp-1,node->left));
            }
            if(node->right){
                q.emplace(make_pair(temp+1,node->right));
            }
        }
        for(auto a: map){
                result.push_back(a.second);
            }
        return result;
    }
};