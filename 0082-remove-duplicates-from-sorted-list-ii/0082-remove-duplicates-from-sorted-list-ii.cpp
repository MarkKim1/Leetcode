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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;

        int val = head->val;
        ListNode* p = head->next;

        if(val != p->val){
            head->next = deleteDuplicates(p);
            return head;
        }else{
            while(p and p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};