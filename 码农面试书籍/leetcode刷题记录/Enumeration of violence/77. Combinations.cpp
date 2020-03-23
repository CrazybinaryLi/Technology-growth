class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(1,res,path,n,k);
        return res;
    }

private:
    static void dfs(int start,vector<vector<int>>& res,vector<int>& path,int n,int k){
        if(path.size()==k){//退出条件1
            res.push_back(path);
            return;
        }
        else if(start==n+1) return;//退出条件2
        dfs(start+1,res,path,n,k);
        path.push_back(start);
        dfs(start+1,res,path,n,k);
        path.pop_back();
    }
};
