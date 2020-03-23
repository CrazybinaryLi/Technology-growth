class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(),nums.end());
        dfs(nums,0,res,tmp);//ษ๎หั
        return res;
    }

private:
    static void dfs(const vector<int>& nums,int start,vector<vector<int>>& res,vector<int>& tmp){
        res.push_back(tmp);
        for(int i=start;i<nums.size();i++){
            if(i!=start&&nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            dfs(nums,i+1,res,tmp);
            tmp.pop_back();
        }
        return;
    }
};
