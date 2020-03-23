/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return reConstructBinaryTree(pre,0,pre.size()-1,vin,0,vin.size()-1);
    }

private:
    TreeNode* reConstructBinaryTree(vector<int>& pre,int pb,int pe,vector<int>& vin,int vb,int ve){
        if(pb>pe||vb>ve) return nullptr;
        TreeNode* root=new TreeNode(pre[pb]);
        int k;
        for(int i=vb;i<=ve;i++){
            if(vin[i]==pre[pb]){
                k=i;//在中序遍历数组中找根节点
                break;
            }
        }
        int llen=k-vb;//左子树的长度
        root->left=reConstructBinaryTree(pre,pb+1,pb+llen,vin,vb,k-1);
        root->right=reConstructBinaryTree(pre,pb+llen+1,pe,vin,k+1,ve);
        return root;
    }
};
