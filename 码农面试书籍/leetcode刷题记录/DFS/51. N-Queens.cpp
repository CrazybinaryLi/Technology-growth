class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        res.clear();
        y_index.clear();
        tmp.clear();
        dfs(n,0,y_index);//从第0行开始安排
        return res;
    }

private:
    vector<vector<string>> res;//最终的结果
    vector<int>        y_index;//皇后列位置
    vector<string>     tmp;
    void dfs(int n,int m,vector<int>& y_index)
    {
        if(m==n)//m表示遍历到第几行了
        {
            for(int i=0; i<n; i++)
            {
                string t(n,'.');
                t[y_index[i]]='Q';
                tmp.push_back(t);
            }
            res.push_back(tmp);
            tmp.clear();
            return;
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(check(m,i,y_index)){
                    y_index.push_back(i);
                    dfs(n,m+1,y_index);
                    y_index.pop_back();
                }
            }
        }
    }

    bool check(int m,int i,vector<int>& y_index){//m是行，i是列。
        for(int j=0;j<m;j++){//跟之前的数据对比
            if(y_index[j]==i||(abs(y_index[j]-i)==abs(j-m))) return false;
        }
        return true;
    }
};
