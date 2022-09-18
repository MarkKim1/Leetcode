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
        ListNode* prev = dummy;
        while(head and head->next){
            //nodes to be swapped
            ListNode* firstNode = head;
            ListNode* secondNode = head->next;
            //swap nodes
            prev->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            
            prev = firstNode;
            head = firstNode->next;
        }
        return dummy->next;
    }
};