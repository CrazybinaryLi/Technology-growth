class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        subsets(nums,res,path,0);
        sort(res.begin(),res.end());
        vector<vector<int>>::iterator iter;
        iter=unique(res.begin(),res.end());//���������ڵ��ظ�Ԫ�طŵ����е�ĩβȥ
        res.erase(iter,res.end());
        return res;
    }

private:
    void subsets(vector<int>& nums,vector<vector<int>>& res,vector<int>& path,int step){
        if(step==nums.size()){
            res.push_back(path);
            return;
        }
        //������nums[step]
        subsets(nums,res,path,step+1);
        //����nums[step]
        path.push_back(nums[step]);
        subsets(nums,res,path,step+1);
        path.pop_back();
    }
};
