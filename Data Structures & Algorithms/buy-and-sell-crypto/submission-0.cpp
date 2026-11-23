class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1){
            return 0;
        }

        int i = 1;
        int minBuyPrice = prices[0];
        int profit = 0;

        while (i < prices.size()) {
            profit = max(profit, prices[i] - minBuyPrice);
            minBuyPrice = min(prices[i], minBuyPrice);
            i += 1;
        }
        return profit;
    }
};
