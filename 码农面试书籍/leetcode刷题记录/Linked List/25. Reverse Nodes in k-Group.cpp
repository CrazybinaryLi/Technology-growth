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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;//����ĳ���
        ListNode* tmp=head;
        while(tmp){
            len++;
            tmp=tmp->next;
        }
        delete tmp;

        if(k>len) return head;

        ListNode dummy(-1);
        dummy.next=head;//һ��Ҫ�ǵð�������������
        ListNode* head2=&dummy;
        while(len>=k){
            ListNode* first=head2->next;
            ListNode* second=head2->next;
            int count=1;
            while(count<k){
                second=second->next;
                count++;
                len--;
            }
            len--;
            head2->next=second->next;
            ListNode* temp;
            temp=second->next;
            ListNode* move=first;
            while(first!=temp){
                first=first->next;
                move->next=head2->next;
                head2->next=move;//ͷ�巨
                move=first;
            }
            while(head2->next!=temp) head2=head2->next;
        }
        return dummy.next;
    }
};
