class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // question looks little difficult to understand but its very easy.
        // basically we can buy and sell stocks same day.
        // for eg: day 1 we buy a stock, we can sell it on day 2 price and keep profit. Now we can buy
        // again on day 2 price and wait for day 3. if day 3 price is high we can sell again and keep profit
        int len=prices.size();
        if(len<=1)
            return 0;
        int max_profit=0;
        for(int i=1;i<len;++i)
        {
            // if there is some profit, grab it
            int profit = (prices[i]-prices[i-1]);
            if(profit>0)
                max_profit+=profit;
        }
        return max_profit;
    }
};