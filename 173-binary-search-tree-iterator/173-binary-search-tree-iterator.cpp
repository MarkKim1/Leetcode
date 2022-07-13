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
class BSTIterator {
public:
    int size,pos;
    vector<int> container;
    BSTIterator(TreeNode* root) {
        inorder(root);
        size = container.size();
        pos = 0;
    }
    
    int next() {
        return container[pos++];
    }
    
    bool hasNext() {
        if(pos <= size-1){
            return true;
        }
        return false;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        container.push_back(root->val);
        inorder(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */