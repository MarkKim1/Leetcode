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
    bool isSame(TreeNode *left, TreeNode *right,bool flag){
        if(left && right && left->val == right->val){
            if(flag){
            flag = isSame(left->left,right->left,flag);
            flag = isSame(left->right,right->right,flag);
            }
            if(flag){
                return flag;
            }else{
                return flag;
            }
        }
        else if(!left && !right){
            if(flag)return true;
            else return false;
        }
        else{
            return false;
        }
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode *left = p;
        TreeNode *right = q;
        bool flag = true;
        return isSame(left,right,flag);
        
    }
};