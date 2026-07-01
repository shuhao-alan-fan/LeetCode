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
        ListNode* cur = head;
        ListNode* prev = nullptr;
        //check len
        int len = 1;
        while(cur->next){
            len++;
            cur = cur->next;
        }
        //delete
        cur = head;
        for(int i = 0; i< len - n; i++){
            prev = cur;
            cur = cur->next;
        }
        
        if(cur == head){
            head = cur->next;
            return head;
        }
        if(prev && cur && cur->next){
            prev ->next = cur->next;
            return head;
        }
        if(prev->next){
            prev->next = nullptr;
            return head;
        }
        
        return nullptr;
    }
};