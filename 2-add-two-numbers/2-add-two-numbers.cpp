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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *list1 = l1;
        ListNode *list2 = l2;
        ListNode *list3 = new ListNode();
        ListNode *head = list3;
        int a = 0,b = 0,c = 0;
        int sum = 0;
        while(list1 != NULL || list2 != NULL){
            a = (list1 != NULL) ? list1->val : 0;
            b = (list2 != NULL) ? list2->val : 0;
            sum = a+b+c;//7,10,8
            
            if(sum > 9){
                list3->next = new ListNode(sum%10); // 0
                c = 1;
            }
            else{
                list3->next = new ListNode(sum);//7,8
                c = 0;
            }
            
            list3 = list3 ->next;
            if(list1 != NULL) list1 = list1->next;
            if(list2 != NULL) list2 = list2->next;
        }
        if(c == 1){
            list3->next = new ListNode(c%10);
        }
        return head->next;
    }
};