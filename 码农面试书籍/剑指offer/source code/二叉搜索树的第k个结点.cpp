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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(k<=0||nodeSum(pRoot)<k) return nullptr;
        if(nodeSum(pRoot->left)+1==k) return pRoot;
        if(nodeSum(pRoot->left)+1<k) return KthNode(pRoot->right,k-nodeSum(pRoot->left)-1);
        return KthNode(pRoot->left,k);
    }

private:
    int nodeSum(TreeNode* root){
        if(!root) return 0;
        return nodeSum(root->left)+nodeSum(root->right)+1;
    }
};
