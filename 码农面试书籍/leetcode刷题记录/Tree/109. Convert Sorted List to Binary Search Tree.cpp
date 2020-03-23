/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> Array;
        while(head!=nullptr){
            Array.push_back(head->val);
            head=head->next;
        }
        return sortedArrayToBST(Array,0,Array.size()-1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& Array,int begin,int end){
        if(begin>end) return nullptr;
        int mid=(begin+end)/2;
        int rootVal=Array[mid];
        TreeNode* root=new TreeNode(rootVal);
        root->left=sortedArrayToBST(Array,begin,mid-1);
        root->right=sortedArrayToBST(Array,mid+1,end);
        return root;
    }
};
