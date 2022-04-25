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
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head;
        ListNode *second = head;
        while(first&& first->next){
            first = first->next->next;
            second = second->next;
            if(second == first){
               break;
            }
        }
        if(!(first&&first->next)) return NULL;
        while (head != second) {
            second = second->next;
            head = head->next;
        }
        
        return head;
    }
};
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) break;
//         }
//         if (!(fast && fast->next)) return NULL;
//         while (head != slow) {
//             head = head->next;
//             slow = slow->next;
//         }
//         return head;
//     }
// };