class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        for(int i=0;i<nums.size();i++) visit[i]=false;
        dfs(nums,res,path);
        return res;
    }

private:
    bool visit[1005];
    void dfs(vector<int>& nums,vector<vector<int>>& res,vector<int>& path){
        if(path.size()==nums.size()){
            if(find(res.begin(),res.end(),path)==res.end())
                res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visit[i]==false){
                path.push_back(nums[i]);
                visit[i]=true;
                dfs(nums,res,path);
                path.pop_back();
                visit[i]=false;
            }
        }
    }
};
