class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        res.clear();
        tmp.clear();
        sort(candidates.begin(),candidates.end());
        dfs(candidates,tmp,target,0);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& candidates,vector<int>& tmp,int target,int start)
    {
        if(target<0) return;
        else if(target==0)
        {
            res.push_back(tmp);
            return;
        }
        for(int i=start; i<candidates.size(); i++)
        {
            if(target-candidates[i]>=0)
            {
                tmp.push_back(candidates[i]);
                dfs(candidates,tmp,target-candidates[i],i);
                tmp.pop_back();
            }
            else if(target-candidates[i]<0) break;
        }
    }
};
