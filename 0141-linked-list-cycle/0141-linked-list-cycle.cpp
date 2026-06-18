/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*,ListNode*> m;
        ListNode *cur = head;
        while(cur){
            if(m.find(cur) != m.end()) return true;
            m[cur] = cur->next;
            cur = cur->next;
        }
        return false;
    }
};