class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int minBuyPrice = prices[0];
        int profit = 0;

        for (int price : prices){
            profit = max(profit, price - minBuyPrice);
            minBuyPrice = min(price, minBuyPrice);
        }
        return profit;
    }
};
