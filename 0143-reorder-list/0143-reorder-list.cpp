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
        if(head->next == nullptr) return;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l2 = slow->next;
        slow ->next = nullptr;

        if(l2 == nullptr) return;
        l2 = inverseLinkedList(l2); // inversed linkedlist;
        
        ListNode *l1 = head;
        while(l1 != nullptr && l2!= nullptr){
            ListNode *temp = l2;
            l2 = l2->next;
            ListNode *temp2 = l1;
            l1 = l1->next;
            temp2->next = temp;
            temp->next = l1;
        }
        
        return;
    }
    ListNode* inverseLinkedList(ListNode * head){
        ListNode * prev = nullptr;
        ListNode * cur = head;
        while(cur != nullptr){
            ListNode * temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
            
        }
        return prev;

    }
};