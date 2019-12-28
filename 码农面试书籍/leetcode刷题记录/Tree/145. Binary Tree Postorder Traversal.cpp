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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postArray;
        postorder(root,postArray);
        return postArray;
    }

private:
    void postorder(TreeNode* root,vector<int>& postArray){
        if(root){
            postorder(root->left,postArray);
            postorder(root->right,postArray);
            postArray.push_back(root->val);
        }
    }
};
