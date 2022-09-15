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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listCount = 0;
        ListNode* node = head;
        while(node){
            node = node->next;
            listCount++;
        }
        if(listCount == n){
            head = head->next;
            return head;
        }
        int compute = listCount-n;
        delete node;
        ListNode* node1 = head;
        for(int i = 0; i < compute-1; i++){
            node1 = node1->next;
        }
        if(!node1->next){
            return NULL;
        }
        node1->next = node1->next->next;
        return head;
    }
};