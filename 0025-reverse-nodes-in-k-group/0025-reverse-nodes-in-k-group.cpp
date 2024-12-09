class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* cur = head;
        ListNode* prev = head;
        cur = cur->next;
        ListNode* test = cur;
        for(int i =0 ; i< k - 1; i++){
            if(test){
                test = test->next;
            }
            else{
                return head;
            }
        }
        for(int i = 0; i< k -1 ; i++){
            if(!cur) break;
            ListNode* nextp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextp;
        }
        head->next = reverseKGroup(cur,k);
        return prev;
    }
    
};