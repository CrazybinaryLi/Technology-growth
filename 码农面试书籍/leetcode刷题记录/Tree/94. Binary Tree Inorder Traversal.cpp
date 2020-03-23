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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inArray;
        inorder(root,inArray);
        return inArray;
    }

private:
    void inorder(TreeNode* root,vector<int>& inArray){
        if(root){
            inorder(root->left,inArray);
            inArray.push_back(root->val);
            inorder(root->right,inArray);
        }
    }
};
