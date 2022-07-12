/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};
        unordered_map<TreeNode*, TreeNode*> map;
        set<int> seen;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            if(temp->left != NULL){
                map[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right != NULL){
                map[temp->right] = temp;
                q.push(temp->right);
            }
        }
        q.push(target);
        
        while(!q.empty()){
            seen.insert(q.front()->val);
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left != NULL and !seen.count(temp->left->val)){
                    q.push(temp->left);
                    seen.insert(temp->left->val);
                }
                if(temp->right != NULL and !seen.count(temp->right->val)){
                    q.push(temp->right);
                    seen.insert(temp->right->val);
                }
                if(map.find(temp) != map.end() and !seen.count(map[temp]->val)){
                    q.push(map[temp]);
                    seen.insert(map[temp]->val);
                }
            }
            k--;
            if(k == 0)break;
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};