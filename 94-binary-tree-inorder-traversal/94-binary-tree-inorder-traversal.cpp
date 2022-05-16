class Solution{
	public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> result;
		TreeNode *curr = root;
		while(curr){
			if(!curr->left){
				result.push_back(curr->val);
				curr = curr->right;
			}else{
				TreeNode *pred = findPredecessor(curr);
				if(pred->right == curr){
					pred->right = NULL;
					result.push_back(curr->val);
					curr = curr->right;
				}else{
					pred->right = curr;
					curr = curr->left;
				}
			}
		}
        return result;
	}
	
	TreeNode* findPredecessor(TreeNode *root){
		TreeNode* curr = root->left;
		while(curr->right && curr->right != root){
			curr = curr->right;
		}
        return curr;
	}
};