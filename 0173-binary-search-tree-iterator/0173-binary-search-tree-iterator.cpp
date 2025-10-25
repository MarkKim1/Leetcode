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
    TreeNode* root;
    vector<int> vec;
    int pos = 0;
    BSTIterator(TreeNode* root) {
        this->root = new TreeNode();
        this->root->val = -1;
        this->root->right = root;
        inorder(root);
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    int next() {
        return vec[pos++];
    }
    
    bool hasNext() {
        if(pos == vec.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */