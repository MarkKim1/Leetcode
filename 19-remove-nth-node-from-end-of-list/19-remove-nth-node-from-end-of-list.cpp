class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *currentNode = head;
        //move currentNode n steps into list
        for(int i = 0; i < n; i++){
            currentNode = currentNode->next;
        }
        if(currentNode == NULL){
            return head->next;
        }
        //move both pointers until currentNode reaches the end of list
        ListNode *nodeBeforeRemoved = head;
        
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            nodeBeforeRemoved = nodeBeforeRemoved->next;   
        }
        
        nodeBeforeRemoved->next = nodeBeforeRemoved->next->next;
        
        return head;
    }
};