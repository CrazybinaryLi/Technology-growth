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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-32767);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* cur=prev->next;
        while(cur){
            if(prev->val==cur->val){
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }else{
                prev=prev->next;
                cur=cur->next;
            }
        }
        return dummy.next;
    }
};
