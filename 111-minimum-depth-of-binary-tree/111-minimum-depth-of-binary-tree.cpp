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
    int min_Depth = 0;
    int result_Depth = INT_MAX;
    queue<pair<TreeNode*, int>> q;
    vector<int> a;
    int _min(){
        if(q.empty()){
            return result_Depth;
        }
        auto sub_q = q.front();
        q.pop();
        auto node = sub_q.first;
        auto level = sub_q.second + 1;
        if(node->left != NULL){
            q.push(make_pair(node->left,level));
        }
        if(node->right != NULL){
            q.push(make_pair(node->right,level));
        }
        if(node->right == NULL && node->left == NULL){
            result_Depth = min(result_Depth,level);
        }
        return _min();
        
    }
    
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        q.push(make_pair(root,min_Depth));
        int result = _min();
        //sort(a.begin(),a.end());
        return result;
    }
};