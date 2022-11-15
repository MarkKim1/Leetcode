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
    int find_depth(TreeNode* root){
        int d = 0;
        auto temp = root;
        while(temp->left){
            temp = temp->left;
            d++;
        }
        return d;
    }
    int exist(int index, int depth, TreeNode* root){
        int left = 0;
        int right = int(pow(2,depth)-1);
        auto node = root;
        for(int i = 0; i < depth; i++){
            int pivot = left + (right-left)/2;
            if(index <= pivot){
                node = node->left;
                right = pivot-1;
            }else{
                node = node->right;
                left = pivot+1;
            }
        }
        return node != NULL;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int depth = find_depth(root);
        int left = 0;
        int right = (int)pow(2,depth)-1;
        while(left <= right){
            int pivot = left+(right-left)/2;
            if(exist(pivot,depth,root)){
                left = pivot+ 1;
            }else{
                right = pivot-1;
            }
        }
        return int(pow(2,depth)-1) + left;
    }
};
    
