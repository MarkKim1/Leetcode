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
                temp_next = curr->next;//save curr->next value to temp_next;
                curr->next = curr->child; // curr->next is now curr->child
                curr->next->prev = curr; // connect prev to curr;
                curr->child = NULL; // curr->child is not needed anymore since curr->next is pointing to child node
                    
                runner = curr->next; // runner gets curr->next node(the child node)
                while(runner->next) runner = runner->next;//runner goes through until it hits runner->next is NULL
                runner->next = temp_next;//after runner reaches final pointer runner points to previously saved next node
                if(runner->next) runner->next->prev = runner;//if temp_next was not null pointer make temp_next to point runner 
                
            }
            curr = curr->next;
        }
        return head;
    }
};