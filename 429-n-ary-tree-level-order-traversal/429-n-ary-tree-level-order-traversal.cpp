/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> result;
        if(root == NULL) return result;
        vector<int> sub;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                sub.push_back(q.front()->val);
                vector<Node*> a = q.front()->children;
                
                for(int i = 0; i < a.size(); i++){
                    q.push(a[i]);
                }
                q.pop();   
            }
            result.push_back(sub);
            sub.clear();
        }
        return result;
    }
};