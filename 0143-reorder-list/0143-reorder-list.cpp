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
        //split in half;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list1 = head;
        ListNode* list2 = slow->next;
        slow->next = nullptr;

        //reverse list2
        ListNode* prev = nullptr;
        ListNode* cur = list2;
        
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        list2 = prev;

        //combine 2 lists;
        
        while(list1 && list2){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
        // if(list2){

        // }


    }
};