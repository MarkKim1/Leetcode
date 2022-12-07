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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(head->next and head->next->next){
            slow = slow->next;
            fast = fast->next->next;
            head = head->next->next;
        }
        if(head->next){
            fast = fast->next->next;
        }
        if(fast == NULL){
            slow = slow->next;
        }
        return slow;
    }
};