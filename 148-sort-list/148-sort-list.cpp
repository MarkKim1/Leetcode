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
    ListNode* sortList(ListNode* head) {
        priority_queue<int,vector<int>, greater<>> pq;
        ListNode* root = new ListNode();
        ListNode* new_head = root;
        while(head){
            pq.push(head->val);
            head = head->next;
        }
        while(!pq.empty()){
            root->next = new ListNode(pq.top());
            root = root->next;
            pq.pop();
        }
        return new_head->next;
    }
};