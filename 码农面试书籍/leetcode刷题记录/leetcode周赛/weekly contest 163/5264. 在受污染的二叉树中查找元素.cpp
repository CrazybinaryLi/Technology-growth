/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class FindElements {
public:
    FindElements(TreeNode* root) {
        this->root=buildTree(root,0);
    }

    bool find(int target) {
        return findVal(this->root,target);
    }

private:
    TreeNode* root;
    TreeNode* buildTree(TreeNode* root,int val){
        if(root==nullptr) return nullptr;
        root->val=val;
        if(root->left) root->left=buildTree(root->left,2*val+1);
        if(root->right) root->right=buildTree(root->right,2*val+2);
        return root;
    }

    bool findVal(TreeNode* root,int target){
        if(root->val==target) return true;
        else if(root->left&&(findVal(root->left,target))) return true;
        else if(root->right&&(findVal(root->right,target))) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
