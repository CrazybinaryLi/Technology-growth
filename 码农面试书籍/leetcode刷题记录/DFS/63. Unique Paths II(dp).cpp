class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        const int m=obstacleGrid.size();
        const int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1]) return 0;
        vector<vector<long long>> f(m,vector<long long>(n,0));
        f[0][0]=obstacleGrid[0][0]?0:1;
        for(int i=1;i<m;i++){//ÐÐ
            if(obstacleGrid[i][0]==0&&f[i-1][0]==1) f[i][0]=1;
            else f[i][0]=0;
        }
        for(int j=1;j<n;j++){//ÁÐ
            if(obstacleGrid[0][j]==0&&f[0][j-1]==1) f[0][j]=1;
            else f[0][j]=0;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1) f[i][j]=0;
                else f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};
