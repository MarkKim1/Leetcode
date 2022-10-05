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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        int curr_depth = 1;
        q.push(root);
        bool finished = false;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr_depth == depth-1){
                    finished = true;
                    if(curr->left){
                        TreeNode* add_left = new TreeNode(val);
                        add_left->left = curr->left;
                        curr->left = add_left;
                    }else{
                        curr->left = new TreeNode(val);
                    }
                    if(curr->right){
                        TreeNode* add_right = new TreeNode(val);
                        add_right->right = curr->right;
                        curr->right = add_right;
                    }else{
                        curr->right = new TreeNode(val);
                    }
                }
                if(curr->left and !finished){
                    q.push(curr->left);
                }
                if(curr->right and !finished){
                    q.push(curr->right);
                }
            }
            if(finished) return root;
            curr_depth++;
        }
        return root;
    }
};