class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
		int buy=0;
		bool transaction=true;
		for(int i=0;i<prices.size();i++){
            if(i==prices.size()-1){
                if(transaction==false) max_profit+=prices[i]-buy;
            }
            else{
			    if(prices[i+1]>prices[i]&&transaction==true){
                    buy=prices[i];
                    transaction=false;
                }
                if(prices[i+1]<prices[i]&&transaction==false){
                    max_profit+=(prices[i]-buy);
                    transaction=true;
                }
            }
		}
        return max_profit;
    }
};
