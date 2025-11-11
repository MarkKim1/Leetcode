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
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeList(l1,l2);
    }
    ListNode* mergeList(ListNode* l1, ListNode* l2){
        ListNode* ptr = new ListNode();
        ListNode* curr = ptr;
        while(l1 and l2){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        while(l1){
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2){
            curr->next = l2;
            curr = curr->next;
            l2 = l2->next;
        }
        return ptr->next;
    }
};