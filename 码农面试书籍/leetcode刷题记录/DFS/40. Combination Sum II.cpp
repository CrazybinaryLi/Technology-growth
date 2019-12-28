class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        res.clear();
        tmp.clear();
        dfs(candidates,target,tmp,0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& candidates,int target,vector<int>& tmp,int start){
        if(target<0) return;
        if(target==0){
            if(find(res.begin(),res.end(),tmp)==res.end())
                res.push_back(tmp);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            tmp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],tmp,i+1);
            tmp.pop_back();
        }
    }
};
