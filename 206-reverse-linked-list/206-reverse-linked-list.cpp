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
    ListNode* reverseList(ListNode* head) {
        ListNode *first = head;
        ListNode *prev = head;
        while(head&&head->next){
            first = head->next;
            head->next = head->next->next;
            first->next = prev;
            prev = first;
        }
        return prev;
    }
};