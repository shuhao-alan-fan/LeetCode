#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* cur = head;
    ListNode* prev = nullptr;
    while(cur){
        ListNode* nextP = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextP;
    }
    return prev;

}


int main(){
    ListNode* node1 = new ListNode(5,nullptr);
    ListNode* node2 = new ListNode(4,nullptr);
    ListNode* node3 = new ListNode(3,nullptr);
    ListNode* head1 = node1;
    node1->next = node2;
    node2->next = node3;
    //ListNode* node4 = new ListNode{9,nullptr};
    //ListNode* node5 = new ListNode{9,nullptr};
    //ListNode* node6 = new ListNode{,nullptr};
    //ListNode* head2 = node4;
    //node4->next = node5;
    //node5-&gt;next = node6;
    ListNode* l3 = reverseList(head1);
    const ListNode* current = l3;
    while(current != nullptr){
        std::cout<< current->val<<" ";
        current = current->next;
    }
    delete node1;
    delete node2;
    delete node3;
    //delete node4;
    //delete node5;
    //delete node6;


}