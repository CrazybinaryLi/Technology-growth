//动态规划
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int res=0;
        if(prices.size()<1) return res;
        if(k>prices.size()/2){
            //如果最大交易次数超过数组长度的一半，则可以进行无数次交易，这个时候用贪心的策略。
            for(int i=1;i<prices.size();i++){
                if(prices[i]>prices[i-1]) res+=prices[i]-prices[i-1];
            }
            return res;
        }
        const int n=prices.size();
        int* dp=new int[n+1]();
        for(int i=1;i<=k;i++){
            int tmpMax=dp[0]-prices[0];
            for(int j=1;j<n;j++){
                int tmpMax2=max(tmpMax,dp[j]-prices[j]);
                dp[j]=max(dp[j-1],prices[j]+tmpMax);
                tmpMax=tmpMax2;
            }
        }
        res=dp[n-1];
        delete []dp;
        return res;
    }
};
