/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> map;
        Node* newhead = head;
        while(newhead){
            map[newhead] = new Node(newhead->val);
            newhead = newhead->next;
        }
        newhead = head;
        while(newhead){
            map[newhead]->next = map[newhead->next];
            map[newhead]->random = map[newhead->random];
            newhead = newhead->next;
        }
        return map[head];
    }
};