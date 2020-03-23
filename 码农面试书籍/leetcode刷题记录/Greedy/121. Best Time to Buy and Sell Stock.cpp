class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int profit=0;
        int stock_buy=prices[0];
        int stock_sell=prices[1];
        if(stock_sell-stock_buy>profit) profit=stock_sell-stock_buy;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<stock_buy) stock_buy=prices[i];
            else if(prices[i]-stock_buy>profit){
                profit=prices[i]-stock_buy;
            }
        }
        return profit;
    }
};
