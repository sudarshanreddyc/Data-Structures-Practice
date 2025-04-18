class Solution
{
public:
    // int f(int i, vector<int> prices, bool buy, int fee, vector<vector<int>>& memo){
    //     if(i >=prices.size()) return 0;
    //     if(memo[i][buy] != -1) return memo[i][buy];
    //     if(buy){ //If you have buy option, you can either buy the current one or skip and go to the next one. Same for sell too.
    //         memo[i][buy] = max(-prices[i] + f(i+1, prices, false, fee, memo), f(i+1, prices, true, fee, memo));
    //     }
    //     else{
    //         memo[i][buy] = max(prices[i] + f(i+1, prices, true, fee, memo) - fee, f(i+1, prices, false, fee, memo));
    //     }
    //     return memo[i][buy];
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     vector<vector<int>> memo(prices.size(), vector<int>(2, -1));
    //     return f(0, prices, true, fee, memo);
    // }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            // Buying state we can buy or skip
            dp[i][1] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            // Selling state we can sell or skip
            dp[i][0] = max(prices[i] + dp[i + 1][1] - fee, dp[i + 1][0]);
        }
        return dp[0][1];
    }
};