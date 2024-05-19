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
        if (head == nullptr) return head;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        ListNode *next = cur->next;
        while(cur != nullptr){
            ListNode* temp = cur;
            cur = temp->next;
            temp->next = prev;
            prev = temp;
            cout<<temp->val<<endl;
            
        }
        head = prev;
       
    

        return head;
    }
};