/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        SaveFromTopToBottom(root,ans);
        return ans;
    }

private:
    void SaveFromTopToBottom(TreeNode* root,vector<int>& ans){
        if(root==nullptr) return;
        else if(root->left==nullptr&&root->right==nullptr){
            ans.push_back(root->val);
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* tmp=root;//标志每一层最后一个结点
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            ans.push_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            if(cur==tmp){
                tmp=q.front();
            }
        }
    }
};
