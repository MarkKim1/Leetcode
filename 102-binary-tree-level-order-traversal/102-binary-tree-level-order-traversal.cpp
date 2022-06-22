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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> sub;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int len;
        while(!q.empty()){
            len = q.size();
            for(int i = 0; i < len; i++){
                sub.push_back(q.front()->val);
                
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            result.push_back(sub);
            sub.clear();
        }
        return result;
    }
};