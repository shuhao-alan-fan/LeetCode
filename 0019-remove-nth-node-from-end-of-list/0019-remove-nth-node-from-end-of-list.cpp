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
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        for(int i = 0; i< n-1; i++){
            fast = fast->next;
        }
        while(fast && fast->next){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(slow == head) return slow->next;
        prev->next = slow->next;
        return head;
    }
};