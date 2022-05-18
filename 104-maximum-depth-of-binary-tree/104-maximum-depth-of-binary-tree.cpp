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
    queue<pair<TreeNode*, int>> next_items;
    int maxdepth = 0;
    public:
    int max_Depth(){
        if(next_items.size() == 0){
            return maxdepth;
        }
        auto next_item = next_items.front();
        next_items.pop();
        
        auto next_node = next_item.first;
        auto next_level = next_item.second + 1;
        maxdepth = max(maxdepth,next_level);
        
        if(next_node->left != NULL){
            next_items.push(make_pair(next_node->left,next_level));
        }
        if(next_node->right != NULL){
            next_items.push(make_pair(next_node->right,next_level));
        }
        
        return max_Depth();
        
    }
    
    int maxDepth(TreeNode* root) {
        if(root ==NULL){
            return 0;
        }
        next_items.push(make_pair(root,0));
        return max_Depth();
    }
};