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
        ListNode dummy(-1);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* cur=prev->next;
        while(cur!=nullptr){
            bool duplicated=false;
            while(cur->next!=nullptr&&cur->val==cur->next->val){
                duplicated=true;
                ListNode* tmp=cur;
                cur=cur->next;
                delete tmp;
            }
            if(duplicated){
                ListNode* tmp=cur;
                cur=cur->next;
                delete tmp;
                continue;
            }
            prev->next=cur;
            prev=prev->next;
            cur=cur->next;
        }
        prev->next=cur;
        return dummy.next;
    }
};
