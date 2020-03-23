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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder,int pb,int pe,vector<int>& inorder,int ib,int ie){
        if(pe<pb) return nullptr;
        TreeNode* root=new TreeNode(preorder[pb]);
        int k=ib;
        while(inorder[k]!=preorder[pb]) k++;
        root->left=buildTree(preorder,pb+1,pb+k-ib,inorder,ib,k-1);
        root->right=buildTree(preorder,pb+k-ib+1,pe,inorder,k+1,ie);
        return root;
    }
};
