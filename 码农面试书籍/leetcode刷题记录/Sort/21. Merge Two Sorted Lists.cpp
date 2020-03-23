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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(-1);
        ListNode* toil=head;
        ListNode* p=l1;
        ListNode* q=l2;
        while(p!=nullptr&&q!=nullptr){
            if(p->val<=q->val){
                toil->next=p;
                p=p->next;
            }else{
                toil->next=q;
                q=q->next;
            }
            toil=toil->next;
        }
        if(p!=nullptr) toil->next=p;
        if(q!=nullptr) toil->next=q;
        return head->next;
    }
};
