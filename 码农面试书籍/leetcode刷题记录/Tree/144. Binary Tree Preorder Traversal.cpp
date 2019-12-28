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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preArray;
        preorder(root,preArray);
        return preArray;
    }

private:
    void preorder(TreeNode* root,vector<int>& preArray){
        if(root){
            preArray.push_back(root->val);
            preorder(root->left,preArray);
            preorder(root->right,preArray);
        }
    }
};
