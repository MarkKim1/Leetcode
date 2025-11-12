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
    ListNode* sortList(ListNode* head) {
        if(!head || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);


        return merge(l1,l2);
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while(l1 and l2){
            if(l1->val < l2->val){
                curr->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                curr->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while(l1){
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2){
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }
        return head->next;
    }
};