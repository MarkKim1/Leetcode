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
    private:
    public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        ListNode *firstNode = head;
        ListNode *secondNode = head->next;
        
        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
        return secondNode;
    }
};