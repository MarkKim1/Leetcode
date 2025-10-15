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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *resultHead = result;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int l1val = 0;
            int l2val = 0;
            if(l1 != NULL){
                l1val = l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2val = l2->val;
                l2 = l2->next;
            }
            int toadd = l1val + l2val + carry;
            result->next = new ListNode(toadd % 10);
            carry = toadd / 10;
            result = result->next;
        }
        if(carry) result->next = new ListNode(carry);
        return resultHead ->next;
    }
};