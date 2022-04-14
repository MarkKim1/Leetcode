class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *currentNode = head;
        ListNode *nodeBeforeRemoved = head;
        
        //for loop n times to make a (0 to nth)gap between currenNode and nodeBeforeRemoved
        for(int i = 0; i < n; i++){
            currentNode = currentNode->next;
        }
        //if n is size of head which removes the first element in the linked list
        if(currentNode == NULL){
            return head->next;
        }
        //move both pointers until currentNode reaches end of the linked list
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            nodeBeforeRemoved = nodeBeforeRemoved->next;
        }
        
        //now make nodeBeforeRemoved points to the pointer after nth node
        nodeBeforeRemoved->next = nodeBeforeRemoved->next->next;
        
        //return the head
        return head;
        
    }
};