class Solution {
public:
    long long numDistinct(string s, string t) {
        if(s.size()==0||t.size()==0) return 0;
        const int n=s.size();
        const int m=t.size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        dp[0][0]=s[0]==t[0]?1:0;
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    if(s[i]!=t[j]) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i-1][0]+1;
                    continue;
                }
                if(s[i]!=t[j]) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
        return dp[n-1][m-1];
    }
};
