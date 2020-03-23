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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        vector<int> tmp;
        tmp.clear();
        TreeNode* curPtr=nullptr;
        queue<TreeNode* > q;
        q.push(root);
        int curlevelcount=1;
        int nextlevelcount=0;
        while(!q.empty()){
            curPtr=q.front();
            q.pop();
            tmp.push_back(curPtr->val);
            curlevelcount--;
            if(curPtr->left){
                q.push(curPtr->left);
                nextlevelcount++;
            }
            if(curPtr->right){
                q.push(curPtr->right);
                nextlevelcount++;
            }
            if(curlevelcount==0){
                curlevelcount=nextlevelcount;
                nextlevelcount=0;
                res.insert(res.begin(),tmp);
                tmp.clear();
            }
        }
        return res;
    }
};
