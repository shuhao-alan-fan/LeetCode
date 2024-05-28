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
        // ListNode * dummy_head = nullptr;
        // while(list.size() > 1){
        //     for(int i = 0; i<lists.size(); i++){
        //         dummy_head = mergeTwoLists(dummy_head,lists[i]);
        //     }
        // }
        
        // return dummy_head;
        int n = lists.size();
        if(n == 0) return NULL;
        return partionLists(0, n - 1, lists);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
             list2->next = mergeTwoLists(list1,list2->next);
             return list2;
        }
    }
    ListNode * partionLists(int lo, int hi, vector<ListNode*>& lists){
        if(hi == lo) return lists[hi];
        int mid = lo + (hi - lo) / 2;
        ListNode *l1 = partionLists(lo,mid,lists);
        ListNode *l2 = partionLists(mid+1,hi,lists);
        return mergeTwoLists(l1,l2);
    }
};