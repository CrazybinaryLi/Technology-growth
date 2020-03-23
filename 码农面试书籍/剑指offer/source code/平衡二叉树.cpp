class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        //用一个变量depth方便记录树的深度。
        int depth=0;
        return IsBalanced(pRoot,depth);
    }

private:
    bool IsBalanced(TreeNode* pRoot,int& depth){
        if(pRoot==nullptr){
            depth=0;
            return true;
        }else if(pRoot->left==nullptr&&pRoot->right==nullptr){
            depth=1;
            return true;
        }
        int ldepth=0,rdepth=0;
        IsBalanced(pRoot->left,ldepth);
        IsBalanced(pRoot->right,rdepth);
        int diff=abs(ldepth-rdepth);
        depth=max(ldepth,rdepth)+1;
        return diff>1?false:true;
    }
};
