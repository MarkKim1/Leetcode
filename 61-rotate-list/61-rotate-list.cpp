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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *ptr = head;
        ListNode *new_tail = head;
        ListNode *newhead = head;
        if(head == NULL || head->next == NULL || k <= 0){
            return head;
        }
        int n = 1;
        while(ptr->next){
            ptr = ptr->next;
            n++;
        }
        ptr->next = head;
        int a = n-k%n-1;
        for(int i = 0; i < a; i++){
           new_tail = new_tail->next;
        }
        for(int i = 0; i <n-k%n; i++){
           newhead = newhead->next;
        }
        new_tail->next = NULL;
            
        return newhead;
    }
};