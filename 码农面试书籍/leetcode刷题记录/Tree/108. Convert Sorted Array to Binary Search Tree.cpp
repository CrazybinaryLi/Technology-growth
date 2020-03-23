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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums,0,nums.size()-1);
    }

private:
    TreeNode* sortedArrayToBST(vector<int>& nums,int begin,int end){
        if(begin>end) return nullptr;
        int rootVal=nums[(begin+end)/2];
        TreeNode* root=new TreeNode(rootVal);
        root->left=sortedArrayToBST(nums,begin,(begin+end)/2-1);
        root->right=sortedArrayToBST(nums,(begin+end)/2+1,end);
        return root;
    }
};
