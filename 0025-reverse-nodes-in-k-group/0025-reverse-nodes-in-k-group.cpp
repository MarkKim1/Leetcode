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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = dummy;

        int count = 0;
        while(prev->next){
            prev = prev->next;
            count++;
        }
        prev = dummy;

        if(prev->next){
            curr = prev->next;
        }
        for(int i = 0; i < count/k; i++){
            for(int j = 0; j < k - 1; j++){
                ListNode* forw = curr->next;
                curr->next = forw->next;
                forw->next = prev->next;
                prev->next = forw;
            }
            if(curr->next){
                curr = curr->next;
                while(prev->next != curr){
                    prev = prev->next;
                }
            }
        }
        return dummy->next;
    }
};