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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* groupPrev = dummy;
        while(true){
            ListNode* kth = getKth(groupPrev,k);
            if(not kth) break;
            ListNode* groupNext = kth->next;
            
            //reverse
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }
        return dummy->next;
    }
    ListNode* getKth(ListNode* curr, int k){
        while(curr and k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
};