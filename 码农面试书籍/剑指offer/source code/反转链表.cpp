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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr||pHead->next==nullptr) return pHead;
        ListNode* h=new ListNode(-1);
        ListNode* p=pHead;
        while(p){
            ListNode* tmp=p->next;
            p->next=h->next;
            h->next=p;
            p=tmp;
        }
        return h->next;
    }
};
