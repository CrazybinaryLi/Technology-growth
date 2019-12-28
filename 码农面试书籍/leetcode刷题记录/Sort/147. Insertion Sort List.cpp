/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* insertionSortList(ListNode* head)
    {
        if(!head||head->next==nullptr)
            return head;
        ListNode* h=new ListNode(INT_MIN);
        ListNode* cur=head;
        ListNode* pre=h;//指向要插入位置的前一个位置
        while(cur)
        {
            ListNode* tmp=cur;
            tmp=tmp->next;
            while(pre->next&&pre->next->val<=cur->val)
            {
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            cur=tmp;
            pre=h;
        }
        return h->next;
    }
};
