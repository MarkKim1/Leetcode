/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        Node *temp_next;
        Node *runner;
        while(curr){
            if(curr->child){
                temp_next = curr->next;
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                    
                runner = curr->next;
                while(runner->next) runner = runner->next;
                runner->next = temp_next;
                if(runner->next) runner->next->prev = runner;
                
            }
            curr = curr->next;
        }
        return head;
    }
};