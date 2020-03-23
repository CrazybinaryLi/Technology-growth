/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead||!pHead->next) return pHead;
        stack<int> val;
        map<int,int> mp;
        ListNode* cur=pHead;
        while(cur){
            ListNode* tmp=cur;
            tmp=tmp->next;
            if(!mp.count(cur->val)){
                val.push(cur->val);
                mp[cur->val]++;
            }
            else{
                while(!val.empty()&&val.top()==cur->val) val.pop();
            }
            delete(cur);
            cur=tmp;
        }
        ListNode* p=new ListNode(-1);
        while(!val.empty()){
            ListNode* tmp=new ListNode(val.top());
            val.pop();
            tmp->next=p->next;
            p->next=tmp;
        }
        return p->next;
    }
};
