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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode dummy(-1);
        ListNode* p=head;
        ListNode* q=head->next;
        ListNode* tail=&dummy;
        while(true){
            ListNode* tp=p;
            ListNode* tq=q;
            tp=tp->next->next;
            if(tp!=nullptr) tq=tq->next->next;
            q->next=tail->next;
            tail->next=q;
            tail=tail->next;
            p->next=tail->next;
            tail->next=p;
            tail=tail->next;
            if(tp&&tq){
                p=tp;
                q=tq;
            }
            else if(tp&&!tq){
                tp->next=tail->next;
                tail->next=tp;
                tail=tail->next;
                break;
            }else break;
        }
        return dummy.next;
    }
};
