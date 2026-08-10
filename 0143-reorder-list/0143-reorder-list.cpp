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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast == head) return;
        if(prev) prev->next = nullptr;
        prev = nullptr;
        ListNode* cur = slow;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        

        ListNode* list1 = head;
        ListNode* list2 = prev;
        ListNode* temp1 = nullptr;
        ListNode* temp2 = nullptr;
        while(list1 && list2){
            temp1 = list1->next;
            temp2 = list2->next;
            
            list1->next = list2;
            if(!temp1) break;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
        return;
        
    }
};