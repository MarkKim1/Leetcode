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
        if(lists.empty()) return NULL;
        ListNode* ans = new ListNode();
        
        int size = lists.size();
        int interval = 1;
        while(interval < size){
            for(int i = 0; i + interval < size; i = i + interval*2){
                lists[i] = mergeSort(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        ans = lists[0];
        return ans;
    }
    
    ListNode* mergeSort(ListNode* result, ListNode* list){
        ListNode* toReturn = new ListNode();
        ListNode* head = toReturn;
        while(result || list){
            if(result and list){
                if(result->val > list->val){
                    toReturn->next = new ListNode(list->val);
                    list = list->next;
                }else{
                    toReturn->next = new ListNode(result->val);
                    result = result->next;
                }
            }else if(!result){
                toReturn->next = new ListNode(list->val);
                list = list->next;
            }else{
                toReturn->next = new ListNode(result->val);
                result = result->next;
            }
            toReturn = toReturn->next;
        }
        return head->next;
    }
};