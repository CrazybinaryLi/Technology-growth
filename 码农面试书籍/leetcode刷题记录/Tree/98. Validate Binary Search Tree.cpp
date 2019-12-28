/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//中序遍历二叉树，有序输出则是BST。
public:
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        res.clear();
        inOrder(root,res);
        bool flag=true;
        for(int i=1;i<res.size();i++){
            if(res[i]>res[i-1]) continue;
            else{
                flag=false;
                break;
            }
        }
        return flag;
    }

private:
    void inOrder(TreeNode* root,vector<int>& res){
        if(root==nullptr) return;
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
    }
};
