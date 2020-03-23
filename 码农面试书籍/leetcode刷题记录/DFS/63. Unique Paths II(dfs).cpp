class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int m=obstacleGrid.size();
        const int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1]) return 0;
        f=vector<vector<int>>(m,vector<int>(n,0));
        f[0][0]=obstacleGrid[0][0]?0:1;
        return dfs(obstacleGrid,m-1,n-1);
    }

private:
    vector<vector<int>> f;
    int dfs(vector<vector<int>>& obstacleGrid,int c,int r){
        if(c<0||r<0) return 0;//数据非法，终止条件。
        if(obstacleGrid[c][r]) return 0;//到不了终点。
        if(c==0&&r==0) return f[0][0];
        if(f[c][r]!=0) return f[c][r];
        f[c][r]+=dfs(obstacleGrid,c-1,r)+dfs(obstacleGrid,c,r-1);
        return f[c][r];
    }
};
