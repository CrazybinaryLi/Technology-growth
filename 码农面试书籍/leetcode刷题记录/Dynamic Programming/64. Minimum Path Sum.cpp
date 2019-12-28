//动态规划+滚动数组
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n=grid.size();
        if(n==0) return 0;
        const int m=grid[0].size();
        vector<int> dp(m,INT_MAX);
        dp[0]=grid[0][0];
        for(int j=1;j<m;j++){
            dp[j]=dp[j-1]+grid[0][j];
        }
        for(int i=1;i<n;i++){
            dp[0]=dp[0]+grid[i][0];
            for(int j=1;j<m;j++){
                dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp[m-1];
    }
};
