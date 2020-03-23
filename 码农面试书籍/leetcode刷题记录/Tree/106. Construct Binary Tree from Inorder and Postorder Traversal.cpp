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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

private:
    TreeNode* buildTree(vector<int>& inorder,int ib,int ie,vector<int>& postorder,int pb,int pe){
        if(ib>ie) return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int k=ib;
        while(inorder[k]!=postorder[pe]) k++;
        root->left=buildTree(inorder,ib,k-1,postorder,pb,pb+k-ib-1);
        root->right=buildTree(inorder,k+1,ie,postorder,pb+k-ib,pe-1);
        return root;
    }
};
