class Solution {//这道题既可以用深度优先搜索，又可以用排列组合的方法。
public:
    int uniquePaths(int m, int n) {
        f=vector<vector<int>> (m,vector<int>(n,0));
        f[0][0]=1;//f[x][y]表示(0,0)->(x,y)的路径条数,f[x][y]存储中间过程，减少了很多重复计算。
        return dfs(m-1,n-1);
    }

private:
    vector<vector<int>> f;
    int dfs(int c,int r){
        if(c==0||r==0) return 1;
        if(f[c][r]>0) return f[c][r];
        else{
            return f[c][r]=dfs(c-1,r)+dfs(c,r-1);
        }
    }
};
