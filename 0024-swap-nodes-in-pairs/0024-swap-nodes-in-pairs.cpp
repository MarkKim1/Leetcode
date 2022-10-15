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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr and curr->next){
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;
            
            //swap
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;
            
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};