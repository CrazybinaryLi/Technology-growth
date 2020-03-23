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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<int> tmp;
        int cur=0;//记录tmp中的当前值
        FindPath(root,expectNumber,tmp,cur);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void FindPath(TreeNode* root,int expectNumber,vector<int>& tmp,int& cur){
        if(root==nullptr) return;
        else if(!root->left&&!root->right&&cur+root->val==expectNumber){
            tmp.push_back(root->val);
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        cur+=root->val;
        tmp.push_back(root->val);
        FindPath(root->left,expectNumber,tmp,cur);
        FindPath(root->right,expectNumber,tmp,cur);
        cur-=root->val;
        tmp.pop_back();
    }
};
