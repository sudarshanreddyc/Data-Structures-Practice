class Solution
{
public:
    int recur(vector<int> &cost, int n, vector<int> &memo)
    {
        if (n >= cost.size())
            return 0;
        if (memo[n] != -1)
            return memo[n];
        memo[n] = cost[n] + min(recur(cost, n + 1, memo), recur(cost, n + 2, memo));
        return memo[n];
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> memo(cost.size(), -1);
        return min(recur(cost, 0, memo), recur(cost, 1, memo));
    }
};