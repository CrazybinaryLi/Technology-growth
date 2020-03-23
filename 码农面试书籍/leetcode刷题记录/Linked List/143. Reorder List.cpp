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
    void reorderList(ListNode* head) {
        if(head==nullptr) return;
        ListNode* cur=head;
        ListNode* tail=head;
        while(tail->next!=nullptr) tail=tail->next;
        while(cur->next&&cur->next->next!=nullptr){
            ListNode* tmp=cur;
            while(tmp->next!=tail) tmp=tmp->next;
            tmp->next=tail->next;
            tail->next=cur->next;
            cur->next=tail;
            cur=cur->next->next;
            tail=tmp;
        }
        return;
    }
};
