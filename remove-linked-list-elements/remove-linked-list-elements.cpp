/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *prev = head;
        ListNode *todelete = nullptr;
        if(head == NULL){
            return NULL;
        }
        if(head->next ==NULL && head->val==val){
            return head->next;
        }
        while(prev&&prev->next){
            if(head->val==val){
                head = head->next;
            }
            else if(curr->val==val){
                prev->next = curr->next;
                curr = prev; 
                
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};