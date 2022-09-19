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
    ListNode* oddEvenList(ListNode* head) {
        int count = 0;
        if(!head or !head->next){
            return head;
        }
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        ListNode* dummy = secondNode;
        while(secondNode and secondNode->next){
            count++;
            firstNode->next = secondNode->next;
            firstNode = firstNode->next;
            if(!firstNode->next){
                firstNode->next = dummy;
                secondNode->next = NULL;
                break;
            }
            secondNode->next = firstNode->next;
            secondNode = secondNode->next;
            if(!secondNode->next){
                firstNode->next = dummy;
                break;
            }
        }
        return head;
    }
};