class Solution {
public:
    int cutRope(int number) {
        if(number==2) return 1;
        if(number==3) return 2;
        vector<int> dp(number+1,1);
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=number;i++){
            for(int j=2;j<=4;j++){
                dp[i]=max(dp[i],dp[i-j]*j);
            }
        }
        return dp[number];
    }
};
