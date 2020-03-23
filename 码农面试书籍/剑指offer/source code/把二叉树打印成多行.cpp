/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ans;
            if(pRoot==nullptr) return ans;
            queue<TreeNode*> tree;
            tree.push(pRoot);
            TreeNode* last=pRoot;
            vector<int> vec;
            while(!tree.empty()){
                TreeNode* tmp=tree.front();
                tree.pop();
                vec.push_back(tmp->val);
                if(tmp->left) tree.push(tmp->left);
                if(tmp->right) tree.push(tmp->right);
                if(last==tmp){
                    ans.push_back(vec);
                    vec.clear();
                    last=tree.back();
                }
            }
            return ans;
        }
};
