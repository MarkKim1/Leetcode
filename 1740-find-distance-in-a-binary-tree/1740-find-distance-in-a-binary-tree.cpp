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
    int findDistance(TreeNode* root, int p, int result) {
        if(p == result) return 0;
        unordered_map<TreeNode*,TreeNode*> map;
        auto temp = root;
        queue<TreeNode*> q;
        auto start = root;
        int ans = 0;
        q.push(temp);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                if(curr->val == p){
                    start = curr;
                }
                q.pop();
                if(curr->left){
                    map[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    map[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        q.push(start);
        unordered_set<int> st;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                if(curr->val == result){
                    return ans;
                }
                st.insert(curr->val);
                if(curr->left and st.find(curr->left->val) == st.end()){
                    q.push(curr->left);
                }
                if(curr->right and st.find(curr->right->val) == st.end()){
                    q.push(curr->right);
                }
                if(map.find(curr) != map.end() and st.find(map[curr]->val) == st.end()){
                    q.push(map[curr]);
                }
            }
            ans++;
        }
        return ans;
    }
};