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
        node = head;
        for(int i = 0; i < compute-1; i++){
            node = node->next;
        }
        if(!node->next){
            return NULL;
        }
        node->next = node->next->next;
        return head;
    }
};