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
        if(!root) return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        bool needToReverse = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> sub(size);
            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(needToReverse) {
                    sub[size-i-1] = temp->val;
                }else{
                    sub[i] = temp->val;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            result.push_back(sub);
            if(needToReverse){
                needToReverse = false;
            }else{
                needToReverse = true;
            }
        }
        return result;
    }
};