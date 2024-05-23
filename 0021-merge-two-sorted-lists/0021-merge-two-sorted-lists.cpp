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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode *node;
        
        ListNode *head;
        if(list1->val < list2->val){
            node = list1;
            head = list1;
            list1 = list1->next;
        }
        else{
            node = list2;
            head = list2;
            list2 = list2->next;
            
        }
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
                node = node->next;
            }
            else{
                node->next = list2;
                list2 = list2->next;
                node = node->next;
            }
        
        } 
        if(list1 == nullptr){
            assert(list2 != nullptr);
            node->next = list2;
        }
        else{
            assert(list1 != nullptr);
            node->next = list1;
        }
        return head;
    }
        
};