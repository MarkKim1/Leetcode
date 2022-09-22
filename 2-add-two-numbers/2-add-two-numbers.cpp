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
        ListNode* result = new ListNode();
        ListNode* head = result;
        int round = 0,sum = 0;
        while(l1 or l2){
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            if(a+b+sum < 10){
                result->next = new ListNode(a+b + sum);
            }else{
                result->next = new ListNode(((a+b+sum)%10));
            }
            sum = (a+b+sum) / 10;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
            result = result->next;
        }
        if(sum != 0){
            result->next = new ListNode(1);
        }
        return head->next;
    }
};