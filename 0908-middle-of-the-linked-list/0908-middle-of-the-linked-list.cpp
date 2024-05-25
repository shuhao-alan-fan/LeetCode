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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode *cur = head;
        ListNode *p = head;
        while(cur != nullptr){
            cur = cur->next;
            count++;
        }
        for(int i = 0; i<count / 2; i++){
            p = p->next;
        }
        
        return p;
    }
};