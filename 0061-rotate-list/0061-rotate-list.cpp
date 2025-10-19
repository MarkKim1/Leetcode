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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int count = 1;
        ListNode* tail = head;
        while(tail->next){
            count++;
            tail = tail->next;
        }
        tail->next = head;
        count = count - (k % count);
        for(int i = 0; i < count; i++){
            tail = tail->next;
        }
        head = tail->next;
        tail->next = NULL;
        return head;
    }
};