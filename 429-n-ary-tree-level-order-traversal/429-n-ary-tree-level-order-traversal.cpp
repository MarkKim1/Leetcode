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
        if(root == nullptr) return {};
        deque<Node*> child(1,root);
        vector<vector<int>> levelOrder({{root->val}});
        while(!child.empty()){
            vector<int> oneLevel;
            int size = child.size();
                 for(int i=0; i<size; ++i){
                     for(auto & children: child[0]->children){
                         child.push_back(children);
                         oneLevel.push_back(children->val);
                     }
                     child.pop_front();
                 }
            levelOrder.push_back(move(oneLevel));
        }
        levelOrder.pop_back();
        return levelOrder;
    }
};