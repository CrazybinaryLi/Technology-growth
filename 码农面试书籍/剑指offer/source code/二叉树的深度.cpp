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
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        else if(!pRoot->left&&!pRoot->right) return 1;
        return 1+max(TreeDepth(pRoot->left),TreeDepth(pRoot->right));
    }
};
