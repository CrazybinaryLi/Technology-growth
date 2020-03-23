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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* tail=dummy.next;
        int len=0;
        while(tail->next!=nullptr) {
            len++;
            prev=prev->next;
            tail=tail->next;
        }
        len++;
        k%=len;
        while(k--){
            prev=&dummy;
            tail=dummy.next;
            while(tail->next!=nullptr) {
                prev=prev->next;
                tail=tail->next;
            }
            prev->next=tail->next;
            tail->next=dummy.next;
            dummy.next=tail;
        }
        return dummy.next;
    }
};
