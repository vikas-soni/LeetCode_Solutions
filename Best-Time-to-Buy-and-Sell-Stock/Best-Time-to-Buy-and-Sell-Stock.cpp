class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // this problem can be solved using brute force by looking at all the index value differences using 2 loops
        // that will be o(n^2) time complexity
        // but with dynamic programming it can be solved in o(n)
        int min_price = INT_MAX;
        int max_profit = 0;
        for(auto price:prices)
        {
            // we try to find the minimum stock price till now
            min_price = std::min(min_price,price);
            // then we calculate profit using this min price and keep track of max profit
            max_profit = std::max(max_profit,price-min_price);
        }
        return max_profit;
    }
};