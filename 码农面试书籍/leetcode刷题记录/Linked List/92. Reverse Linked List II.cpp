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
        ListNode dummy(-1);//����һ��ͷ���
        dummy.next=head;//ͷ���ָ���һ�����

        ListNode* prev=&dummy;
        for(int i=0;i<m-1;i++){
            prev=prev->next;
        }
        ListNode* const head2=prev;//�����ĵ�һ�����
        ListNode* cur=prev->next;//Ҫ����ĵ�ǰ���
        head2->next=nullptr;
        for(int i=m;i<=n;i++){
            prev=cur->next;
            cur->next=head2->next;//����ͷ�巨
            head2->next=cur;
            cur=prev;
        }
        cur=head2;
        while(cur->next!=nullptr) cur=cur->next;
        cur->next=prev;
        return dummy.next;
    }
};
