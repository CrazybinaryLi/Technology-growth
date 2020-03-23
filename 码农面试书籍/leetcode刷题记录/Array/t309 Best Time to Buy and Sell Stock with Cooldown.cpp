class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto size = prices.size();
        if (size <= 1)
            return 0;

        vector<int> wait(size), hold(size), cool(size);
        wait[0] = 0;
        hold[0] = -prices[0];
        cool[0] = 0;
        for (int i = 1; i < size; ++i)
        {
            wait[i] = max(wait[i - 1], cool[i - 1]);
            hold[i] = max(hold[i - 1], wait[i - 1] - prices[i]);
            cool[i] = hold[i - 1] + prices[i];
        }
        return max(wait[size - 1], cool[size - 1]);
    }
};
