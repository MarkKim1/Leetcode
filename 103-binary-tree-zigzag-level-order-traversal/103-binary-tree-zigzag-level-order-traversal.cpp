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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        int flag = 0;
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root);
        result.push_back({{root->val}});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right){
                    q.push(temp->right);
                    curr.push_back(temp->right->val);
                }
                if(temp->left){
                    q.push(temp->left);
                    curr.push_back(temp->left->val);
                }
            }
            if(flag == 0){
                result.push_back(curr);
                curr.clear();
                flag = 1;
            }else{
                reverse(curr.begin(),curr.end());
                result.push_back(curr);
                flag = 0;
                curr.clear();
            }
        }
        result.pop_back();
        return result;
    }
};