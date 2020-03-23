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
    ListNode* sortList(ListNode* head) {
        if(!head||head->next==nullptr) return head;
        //快慢指针找到中间节点,快指针一次走两步，慢指针一次走一步。
        ListNode* fast=head,*slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=slow;
        slow=slow->next;
        fast->next=nullptr;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);
        return mergeTwoLists(l1,l2);
    }

private:
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
