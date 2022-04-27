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
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
        ListNode *firstHalfEnd = endOfFirstHalf(head);//[1,2]
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);//[2]
        
        ListNode *p1 = head;
        ListNode *p2 = secondHalfStart;
        bool result = true;
        
        while(result && p2 != NULL){
            if(p1->val != p2->val)result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return result;
    }
private:
    ListNode* reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr != nullptr){
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    
    ListNode* endOfFirstHalf(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next&&fast->next->next){
            slow = slow ->next;
            fast = fast->next->next;
        }
        return slow;
    }
};