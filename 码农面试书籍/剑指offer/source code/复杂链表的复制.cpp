/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==nullptr) return nullptr;
        RandomListNode* cur=pHead;
        while(cur){//从旧链表中创建新链表
            RandomListNode* copy=new RandomListNode(cur->label);
            copy->next=cur->next;
            cur->next=copy;
            cur=copy->next;
        }
        cur=pHead;
        while(cur){//根据旧链表的兄弟结点，初始化新链表的兄弟结点。
            cur->next->random=cur->random==nullptr?nullptr:cur->random->next;
            cur=cur->next->next;
        }
        RandomListNode* newHead=pHead->next;//新的链表头
        cur=pHead;
        while(cur){//将新链表从旧链表中抽离出来。
            RandomListNode* cloneNode=cur->next;
            cur->next=cloneNode->next;
            cloneNode->next=cur->next==nullptr?nullptr:cur->next->next;
            cur=cur->next;
        }
        return newHead;
    }
};
