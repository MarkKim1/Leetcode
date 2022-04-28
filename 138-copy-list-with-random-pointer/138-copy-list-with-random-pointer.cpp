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
        unordered_map<Node*,Node*> hash;
        Node *ptr = head;
        while(ptr){
            hash[ptr] = new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr){
            hash[ptr]->next = hash[ptr->next];
            hash[ptr]->random = hash[ptr->random];
            ptr = ptr->next;
        }
        ptr = head;
        return hash[ptr];
    }
};