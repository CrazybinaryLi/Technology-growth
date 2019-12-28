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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,res);
        return res;
    }

private:
    void levelorder(TreeNode* root,vector<vector<int>>& res){
        if(root==nullptr) return;
        int curLevelCount=1,nextLevelCount=0;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* curPtr=nullptr;
        vector<int> tmp;
        tmp.clear();
        while(!q.empty()){
            curPtr=q.front();
            q.pop();
            tmp.push_back(curPtr->val);
            curLevelCount--;
            if(curPtr->left){
                q.push(curPtr->left);
                nextLevelCount++;
            }
            if(curPtr->right){
                q.push(curPtr->right);
                nextLevelCount++;
            }
            if(curLevelCount==0){
                res.push_back(tmp);
                tmp.clear();
                curLevelCount=nextLevelCount;
                nextLevelCount=0;
            }
        }
    }
};
