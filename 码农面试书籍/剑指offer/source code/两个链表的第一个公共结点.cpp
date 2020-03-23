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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1=GetListLen(pHead1);
        int len2=GetListLen(pHead2);
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        int k=abs(len1-len2);
        if(len1>len2){
            while(k--) p1=p1->next;
        }else{
            while(k--) p2=p2->next;
        }
        while(p1&&p2){
            if(p1!=p2){
                p1=p1->next;
                p2=p2->next;
            }
            else break;
        }
        return p1;
    }

private:
    int GetListLen(ListNode* pHead){
        int len=0;
        ListNode* cur=pHead;
        while(cur){
            len++;
            cur=cur->next;
        }
        return len;
    }
};
