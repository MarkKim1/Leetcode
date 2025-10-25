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
    stack<TreeNode*> stk;
    TreeNode* root;
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder(this->root);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        stk.push(root);
        inorder(root->left);
    }
    int next() {
        TreeNode* curr = stk.top();
        stk.pop();
        inorder(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */