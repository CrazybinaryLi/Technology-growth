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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr||k<=0) return nullptr;
        ListNode* p=pListHead;
        ListNode* q=pListHead;
        unsigned int m=k-1;
        while(m>0&&q){
            q=q->next;
            m--;
        }
        if(m>0||!q) return nullptr;
        while(q->next){
            p=p->next;
            q=q->next;
        }
        return p;
    }
};
