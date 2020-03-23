//思路很简单，同时对两棵树进行递归遍历，看每次遍历的值相同与否。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr) return true;
        if(p||q){
            if(p==nullptr||q==nullptr) return false;
            if(p->val!=q->val) return false;
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        }
        return true;
    }
};
