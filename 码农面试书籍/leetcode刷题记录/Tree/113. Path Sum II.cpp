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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;//中间结果
        pathSum(root,res,cur,sum);
        return res;
    }

private:
    void pathSum(TreeNode* root,vector<vector<int>>& res,vector<int>& cur,int sum){
        if(root==nullptr) return;
        cur.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr&&root->val==sum) res.push_back(cur);
        pathSum(root->left,res,cur,sum-root->val);
        pathSum(root->right,res,cur,sum-root->val);
        cur.pop_back();
    }
};
