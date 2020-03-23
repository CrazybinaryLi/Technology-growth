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
    void recoverTree(TreeNode* root) {
        vector<TreeNode* > node;
        vector<int> valu;
        inorder(root,node,valu);
        sort(valu.begin(),valu.end());
        for(int i=0;i<valu.size();i++){
            node[i]->val=valu[i];
        }
    }
private:
    void inorder(TreeNode* root,vector<TreeNode* >& node,vector<int>& valu){
        if(root){
            if(root->left){
                inorder(root->left,node,valu);
            }
            node.push_back(root);
            valu.push_back(root->val);
            if(root->right){
                inorder(root->right,node,valu);
            }
        }
    }
};
