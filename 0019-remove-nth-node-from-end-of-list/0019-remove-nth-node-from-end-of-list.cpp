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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ((head->next == nullptr) ) return nullptr;
        int count = 0;
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *p = head;
        while(cur != nullptr){
            cur = cur->next;
            count++;
        }
       
        for(int i = 0; i< count - n ; i++){
            prev = p;
            p = p->next;
        }
        if(prev == nullptr){
           return p->next; 
        }

        if(prev->next && prev->next->next ){
            ListNode *temp = prev->next->next;
            prev->next  = temp;
        }
        else{
            prev->next = nullptr;
        }
        return head;
    }
};