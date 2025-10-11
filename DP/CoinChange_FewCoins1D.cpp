class Solution
{
public:
    int recur(vector<int> &coins, int index, long target, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return 1e9;
        }

        // another base case
        // if (index < 0) {                // ✅ no coins left
        //     if (target == 0) return 0;  // formed target exactly
        //     return 1e9;                 // can't form
        // }
        if (dp[index][target] != -1)
            return dp[index][target];
        int notTake = recur(coins, index - 1, target, dp);

        int take = 1e9;
        if (coins[index] <= target)
        {
            take = 1 + recur(coins, index, target - coins[index], dp);
        }

        return dp[index][target] = min(take, notTake);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = recur(coins, coins.size() - 1, amount, dp);
        return res == 1e9 ? -1 : res;
    }
};