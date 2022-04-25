/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL && headB == NULL){
            return nullptr;
        }
        unordered_map<ListNode*,int> hash;
        int i = 0;
        while(headA){
            hash[headA] = i++;
            headA = headA->next;
        }
        while(headB){
            if(hash.find(headB) != hash.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};