class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int max_Profit=0;
        int low_prices=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]-low_prices>max_Profit){
                max_Profit=prices[i]-low_prices;
            }
            if(prices[i]<low_prices){
                low_prices=prices[i];
            }
        }
        return max_Profit;
    }
};
