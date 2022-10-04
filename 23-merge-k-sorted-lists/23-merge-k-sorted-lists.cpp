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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1){
            return lists[0];
        }
        
        int interval = 1;
        while(interval < lists.size()){
            for(int i = 0; i + interval < lists.size(); i = i + interval*2){
                lists[i] = merge(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* curr = new ListNode();
        ListNode* ans = curr;
        while(l1 and l2){
            if(l1->val < l2->val){
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
            }else{
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
        }
        while(l1 == NULL and l2){
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
            while(l2 == NULL and l1){
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
            }
        return ans->next;
    }
};