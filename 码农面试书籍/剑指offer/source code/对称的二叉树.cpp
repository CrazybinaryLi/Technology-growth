/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==nullptr) return true;
        return comRoot(pRoot->left,pRoot->right);
    }

private:
    bool comRoot(TreeNode* left,TreeNode* right){
        if(left==nullptr) return right==nullptr?true:false;
        if(right==nullptr) return false;
        if(left->val!=right->val) return false;
        return comRoot(left->left,right->right)&&comRoot(left->right,right->left);
    }
};
