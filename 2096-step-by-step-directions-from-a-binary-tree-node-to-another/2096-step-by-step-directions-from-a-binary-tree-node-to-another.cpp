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
    string s_p ="";
    string d_p = "";
    string sub = "";
    string getDirections(TreeNode* root, int startValue, int destValue) {
        find(root,startValue,destValue);
        if(s_p.empty()) return d_p;
        if(d_p.empty()) return string(s_p.size(),'U');
        // cout << s_p << endl;
        // cout << d_p << endl;
        int i = 0;
        while(i < s_p.size() and i < d_p.size() and s_p[i] == d_p[i]){
            i++;
        }
        return string(s_p.size()-i,'U') + d_p.substr(i);
        
    }
    void find(TreeNode* root,int start,int dest){
        if(!root) return;
        if(root->val == start){
            s_p = sub;
        }
        if(root->val == dest){
            d_p = sub;
        }
        if(root->left){
            sub+='L';
            find(root->left,start,dest);
            sub.pop_back();
        }
        if(root->right){
            sub+='R';
            find(root->right,start,dest);
            sub.pop_back();
        }
    }
};