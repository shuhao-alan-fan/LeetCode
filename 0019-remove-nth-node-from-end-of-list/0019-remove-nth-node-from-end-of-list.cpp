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
        ListNode* dummy_head = head;
        ListNode* c = head;
        if(!c) return nullptr;
        int cnt = 0;
        while(c->next){
            c = c->next;
            cnt++;
        }
        ListNode* cur = head;
        ListNode* prev = nullptr;
        for(int i = 0; i<cnt- n+1; i++){
            prev = cur;
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        if(!prev){
            if(temp) return temp;
            else{
                return nullptr;
            }
        }
        else{
            prev->next = temp;
            return head;
        }
        return head;
    }
};