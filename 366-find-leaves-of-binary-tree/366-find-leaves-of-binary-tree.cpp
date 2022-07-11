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
    vector<vector<int>> findLeaves(TreeNode* root) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int depth = DFS(root,pq);
        vector<vector<int>> result(depth+1);
        int size = pq.size();
        while(!pq.empty()){
            result[pq.top().first].push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    int DFS(TreeNode* root,priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>& pq){
        if(root == NULL) return -1;
        
        int left = DFS(root->left,pq);
        int right = DFS(root->right,pq);
        int curr = max(left,right)+1;
        pq.push({curr,root->val});
        return curr;
    }
};