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
    ListNode* merge2Lists(ListNode* l1,ListNode* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val < l2->val){
            l1->next = merge2Lists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = merge2Lists(l1,l2->next);
            return l2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //if(lists.empty()) return nullptr;
        ListNode* ans = nullptr;
        for(int i = 0;i < lists.size();++ i){
            ans = merge2Lists(ans,lists[i]);
        }
        return ans;
    }
};
