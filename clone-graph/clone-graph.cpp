/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        if(map.find(node) == map.end()){
            map[node] = new Node(node->val,vector<Node*>());
            for(auto adj : node->neighbors){
                map[node]->neighbors.push_back(cloneGraph(adj));
            }
        }
        return map[node];
    }
private:
    unordered_map<Node*,Node*> map;
};