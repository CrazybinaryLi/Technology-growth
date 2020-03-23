/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* p=head;
        vector<int> res;
        while(p){
            res.push_back(p->val);
            p=p->next;
        }
        reverse(res.begin(),res.end());//vector逆置操作
        return res;
    }
};
