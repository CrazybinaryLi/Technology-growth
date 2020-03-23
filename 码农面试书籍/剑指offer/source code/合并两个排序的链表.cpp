/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode h(-1);
        ListNode* H=&h;
        ListNode* toil=H;
        ListNode* p=pHead1;
        ListNode* q=pHead2;
        while(p&&q){
            if(p->val<=q->val){
                ListNode* tmp=p;
                tmp=tmp->next;
                p->next=toil->next;
                toil->next=p;
                toil=toil->next;
                p=tmp;
            }else{
                ListNode* tmp=q;
                tmp=tmp->next;
                q->next=toil->next;
                toil->next=q;
                toil=toil->next;
                q=tmp;
            }
        }
        while(p){
            ListNode* tmp=p;
            tmp=tmp->next;
            p->next=toil->next;
            toil->next=p;
            toil=toil->next;
            p=tmp;
        }
        while(q){
            ListNode* tmp=q;
            tmp=tmp->next;
            q->next=toil->next;
            toil->next=q;
            toil=toil->next;
            q=tmp;
        }
        return H->next;
    }
};
