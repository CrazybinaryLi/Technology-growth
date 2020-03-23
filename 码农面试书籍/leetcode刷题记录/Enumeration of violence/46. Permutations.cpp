class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums,res,path);
        return res;
    }

private:
    static void dfs(vector<int>& nums,vector<vector<int>>& res,vector<int>& path){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(auto i:nums){
            auto pos=find(path.begin(),path.end(),i);
            if(pos==path.end()){
                path.push_back(i);
                dfs(nums,res,path);
                path.pop_back();
            }
        }
    }
};
