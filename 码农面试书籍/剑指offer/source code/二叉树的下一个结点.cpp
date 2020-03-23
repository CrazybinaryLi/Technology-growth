/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return nullptr;
        if(pNode->right){
            TreeLinkNode* tmp=pNode->right;
            while(tmp->left) tmp=tmp->left;
            return tmp;
        }
        while(pNode->next){
            TreeLinkNode* pRoot=pNode->next;
            if(pRoot->left==pNode) return pRoot;
            pNode=pNode->next;
        }
        return nullptr;
    }
};
