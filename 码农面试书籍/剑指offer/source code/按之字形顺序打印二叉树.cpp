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
        stack<int> st;//偶数行放在栈中
        queue<int> q;//奇数行放在队列中
        queue<TreeNode*> tree;//采用层序遍历的方式
        tree.push(pRoot);
        TreeNode* last=pRoot;//标记每一层的最后一个结点
        int k=1;//层数
        while(!tree.empty()){
            TreeNode* tmp=tree.front();
            tree.pop();
            if(tmp->left) tree.push(tmp->left);
            if(tmp->right) tree.push(tmp->right);
            if(k%2!=0){//奇数层
                q.push(tmp->val);
            }else{
                st.push(tmp->val);
            }
            if(last==tmp){
                vector<int> vec;
                if(k%2!=0){
                    while(!q.empty()){
                        vec.push_back(q.front());
                        q.pop();
                    }
                }else{
                    while(!st.empty()){
                        vec.push_back(st.top());
                        st.pop();
                    }
                }
                ans.push_back(vec);
                k++;
                last=tree.back();
            }
        }
        return ans;
    }
};
