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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(-1);//设立一个头结点
        dummy.next=head;//头结点指向第一个结点

        ListNode* prev=&dummy;
        for(int i=0;i<m-1;i++){
            prev=prev->next;
        }
        ListNode* const head2=prev;//子链的第一个结点
        ListNode* cur=prev->next;//要插入的当前结点
        head2->next=nullptr;
        for(int i=m;i<=n;i++){
            prev=cur->next;
            cur->next=head2->next;//采用头插法
            head2->next=cur;
            cur=prev;
        }
        cur=head2;
        while(cur->next!=nullptr) cur=cur->next;
        cur->next=prev;
        return dummy.next;
    }
};
