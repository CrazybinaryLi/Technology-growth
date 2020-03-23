/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr) return;
        else if(pRoot->left==nullptr&&pRoot->right==nullptr) return;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        TreeNode* tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
    }
};
