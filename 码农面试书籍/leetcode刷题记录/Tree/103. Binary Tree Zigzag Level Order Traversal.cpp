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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagLevelOrder(root,res);
        return res;
    }

private:
    void zigzagLevelOrder(TreeNode* root,vector<vector<int>>& res){
        if(root==nullptr) return;
        int curLevelCount=1,nextLevelCount=0;
        queue<TreeNode* > q;
        q.push(root);
        TreeNode* curPtr=nullptr;
        vector<int> tmp;
        tmp.clear();
        bool flag=true;
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
                if(flag==false) reverse(tmp.begin(),tmp.end());
                flag=!flag;
                res.push_back(tmp);
                tmp.clear();
                curLevelCount=nextLevelCount;
                nextLevelCount=0;
            }
        }
    }
};
