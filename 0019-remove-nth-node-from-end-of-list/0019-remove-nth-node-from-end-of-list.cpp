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
        if(!head) return nullptr;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* fast = head;
        for(int i = 0; i<n-1; i++){
            if(fast && fast->next)    fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(slow == head){
            head = slow->next;
            return head;
        }
        prev->next = slow->next;

        return head;
    }
};