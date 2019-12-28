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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        return isBalanced(root->left)&&isBalanced(root->right)&&(abs(height(root->left)-height(root->right))<=1?true:false);
    }

private:
    int height(TreeNode* p){
        int h=0;
        if(p==nullptr) return 0;
        else if(p->right==nullptr&&p->left==nullptr) return 1;
        else{
            int lh=height(p->left);
            int rh=height(p->right);
            h=max(lh,rh)+1;
        }
        return h;
    }
};
