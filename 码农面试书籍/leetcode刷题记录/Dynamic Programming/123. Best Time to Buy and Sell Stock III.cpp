class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int res=0;
        vector<int> f(prices.size(),0);
        vector<int> g(prices.size(),0);
        for(int i=0;i<prices.size();i++){
            f[i]=maxProfitPart(prices,0,i);
            g[i]=maxProfitPart(prices,i,prices.size()-1);
            res=max(res,f[i]+g[i]);
        }
        return res;
    }

private:
    int maxProfitPart(vector<int>& prices,int start,int end){
        if(start>=end) return 0;
        int res=INT_MIN;
        int buy=prices[start];
        for(int i=start;i<=end;i++){
            if(prices[i]<buy){
                buy=prices[i];
            }
            if(prices[i]-buy>res) res=prices[i]-buy;
        }
        return res;
    }
};
