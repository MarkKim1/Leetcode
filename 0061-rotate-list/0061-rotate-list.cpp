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
        if(!head)return NULL;
        queue<ListNode*> q;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            q.push(temp);
            temp = temp->next;
            size++;
        }
        if(k %size == 0) return head;
        int nth = size - (k % size);
        
        ListNode* curr = new ListNode();
        ListNode* newhead = curr;
        for(int i = 0; i < nth; i++){
            curr->next = new ListNode(q.front()->val);
            curr = curr->next;
            q.pop();
        }
        newhead = newhead->next;
        ListNode* result = q.front();
        while(q.front()->next){
            q.front() = q.front()->next;
        }
        q.front()->next = newhead;
        return result;
        
    }
};