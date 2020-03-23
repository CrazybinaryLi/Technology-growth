/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if(n==0){
            vector<TreeNode*> res;
            res.clear();
            return res;
        }
        else
            return generateTrees(1,n);
    }

private:
    vector<TreeNode*> generateTrees(int start,int end)
    {
        vector<TreeNode*> subTree;
        if(start>end)
        {
            subTree.push_back(nullptr);
            return subTree;
        }
        for(int k=start; k<=end; k++)
        {
            vector<TreeNode*> leftTree=generateTrees(start,k-1);
            vector<TreeNode*> rightTree=generateTrees(k+1,end);
            for(auto i:leftTree)
            {
                for(auto j:rightTree)
                {
                    TreeNode* root=new TreeNode(k);
                    root->left=i;
                    root->right=j;
                    subTree.push_back(root);
                }
            }
        }
        return subTree;
    }
};
