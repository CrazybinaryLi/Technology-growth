class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        return combine(n,k,1);
    }
    vector<vector<int>> combine(int n,int k,int start){
        vector<vector<int>> ret;
        if(n<k||n-start+1<k) return ret;
        else if(k==1){
            for(int i=start;i<=n;i++){
                ret.push_back({i});
            }
            return ret;
        }else{
            vector<vector<int>> temp1=combine(n,k-1,start+1);
            for(int i=0;i<temp1.size();i++){
                temp1[i].push_back(start);
                ret.push_back(temp1[i]);
            }
            vector<vector<int>> temp2=combine(n,k,start+1);
            for(int i=0;i<temp2.size();i++){
                ret.push_back(temp2[i]);
            }
            return ret;
        }
    }
};

/*
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> ans;
        vector<int> temp;

        backtracking(1, n, k, ans, temp);

        return ans;
    }

private:
    void backtracking(int begin, int n, int k, vector<vector<int>>& ans, vector<int>& temp)
    {
        if (k == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = begin; n - i + 1 >= k; ++i)
        {
            temp.push_back(i);
            backtracking(i + 1, n, k - 1, ans, temp);
            temp.pop_back();
        }
    }
};*/
