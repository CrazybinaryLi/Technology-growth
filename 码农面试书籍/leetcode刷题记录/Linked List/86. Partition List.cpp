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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* bp=&dummy;
        while(bp->next!=nullptr){
            if(bp->next->val<x) bp=bp->next;
            else break;
        }
        ListNode* cur=bp->next;
        ListNode* prev=bp;
        while(cur!=nullptr){
            if(cur->val<x){//β�巨
                prev->next=cur->next;
                cur->next=bp->next;
                bp->next=cur;
                bp=bp->next;
                cur=prev->next;
            }else{
                cur=cur->next;
                prev=prev->next;
            }
        }
        return dummy.next;
    }
};
