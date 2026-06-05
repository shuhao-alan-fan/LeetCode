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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        ListNode* cur = head->next;
        ListNode* n = cur->next;

        while(cur != nullptr){
            cur->next = prev;
            head->next = nullptr;
            prev = cur;
            cur = n;
            if(cur != nullptr){
                n = cur->next;
            }
            else{
                return prev;
            }
        }
        return prev;
    }
};