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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();

        ListNode* lefttail = left;
        ListNode* righttail = right;

        while(head){
            if(head->val < x){
                lefttail->next = new ListNode(head->val);
                lefttail = lefttail->next;
            }else{
                righttail->next = new ListNode(head->val);
                righttail = righttail->next;
            }
            head = head->next;
        }
        lefttail->next = right->next;
        return left->next;
    }
};