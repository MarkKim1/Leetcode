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
private:
    unordered_map<Node*, Node*> map;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone = new Node(node->val,vector<Node*>());
        map[node] = clone;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor : curr->neighbors){
                if(map.find(neighbor) == map.end()){
                    map[neighbor] = new Node(neighbor->val,vector<Node*>());
                    q.push(neighbor);
                }
                map[curr]->neighbors.push_back(map[neighbor]);
            }
        }
        return clone;
    }
};