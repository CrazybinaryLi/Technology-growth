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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;//ÖÕÖ¹Ìõ¼þ
        flatten(root->left);
        flatten(root->right);
        if(root->left==nullptr) return;//¼ôÖ¦
        TreeNode* p=root->left;
        while(p->right) p=p->right;
        p->right=root->right;
        root->right=root->left;
        root->left=nullptr;
    }
};
