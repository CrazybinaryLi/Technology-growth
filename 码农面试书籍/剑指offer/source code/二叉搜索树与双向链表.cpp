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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {//采用中序遍历的方法，用一个pre指针记录前一个结点。
        if(pRootOfTree==nullptr) return nullptr;
        TreeNode* pre=nullptr;
        convertHelp(pRootOfTree,pre);
        TreeNode* res=pRootOfTree;
        while(res->left) res=res->left;
        return res;
    }

private:
    void convertHelp(TreeNode* pRootOfTree,TreeNode* &pre){
        if(pRootOfTree==nullptr) return;
        convertHelp(pRootOfTree->left,pre);
        pRootOfTree->left=pre;
        if(pre) pre->right=pRootOfTree;
        pre=pRootOfTree;
        convertHelp(pRootOfTree->right,pre);
    }
};
