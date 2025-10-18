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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;
        for(int i = 0; i < n; i++){
            first = first->next;
        }
        if(!first) return head->next;
        while(first->next){
            second = second->next;
            first = first->next;
        }
        ListNode* mid = second->next;
        second->next = second->next->next;
        mid = NULL;
        return head;
    }
};