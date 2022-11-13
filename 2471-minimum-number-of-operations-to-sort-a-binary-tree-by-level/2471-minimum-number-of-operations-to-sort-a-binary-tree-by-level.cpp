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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> vec;
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    vec.push_back(curr->left->val);
                }
                if(curr->right){
                    q.push(curr->right);
                    vec.push_back(curr->right->val);
                }
            }
            ans += helper(vec);
        }
        return ans;
    }
    int helper(vector<int>& vec){
        unordered_map<int,int> map;
        vector<bool>visited(vec.size(),false);
        int ans = 0;
        for(int i = 0; i < vec.size(); i++){
            map[vec[i]] = i;
        }
        sort(vec.begin(),vec.end());
        for(int i = 0; i < vec.size(); i++){
            if(visited[i] || map[vec[i]] == i){
                continue;
            }
            int j = i;
            int cycle = 0;
            while(visited[j] == false){
                visited[j] = true;
                j = map[vec[j]];
                cycle++;
            }
            if(cycle > 0){
                ans += cycle -1;
            }
        }
        return ans;
    }
};