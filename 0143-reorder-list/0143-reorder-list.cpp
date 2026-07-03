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
//  cut in half, reverse second half, merge two list
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* c = head;
        int count = 1;
        while(c && c->next){
            c = c->next;
            count++;
        }
        if(count == 1) return;
        int half = count/2;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* prev = nullptr;
        for(int i = 0; i<half; i++){
            prev = p2;
            p2 = p2->next;
        }
        prev->next = nullptr;
        //reverse
        ListNode* p = nullptr;
        while(p2){
            ListNode* n = p2->next;
            p2->next = p;
            p = p2;
            p2 = n;
        }
        p2 = p;
        //merge
        while(p1 && p2){
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;

            p1->next = p2;
            if (n1) p2->next = n1;
            p1 = n1;
            p2 = n2;
        }
        
    }
};