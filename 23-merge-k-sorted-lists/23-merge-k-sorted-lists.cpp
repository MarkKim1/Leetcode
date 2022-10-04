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
        vector<int> result;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i] and lists[i]->next){
                result.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            if(lists[i]){
                result.push_back(lists[i]->val);
            }
        }
        sort(result.begin(),result.end());
        ListNode* curr = new ListNode();
        ListNode* head = curr;
        for(int i = 0; i < result.size(); i++){
            curr->next = new ListNode(result[i]);
            curr = curr->next;
        }
        return head->next;
    }
};