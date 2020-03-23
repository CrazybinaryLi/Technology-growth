class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=number;i++){
            dp[i]+=1;
            for(int j=1;j<=i-1;j++){
                dp[i]+=dp[j];
            }
        }
        return dp[number];
    }
};
