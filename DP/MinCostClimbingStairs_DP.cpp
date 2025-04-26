class Solution
{
public:
    // int recur(vector<int> &cost, int n, vector<int> &memo)
    // {
    //     if (n >= cost.size())
    //         return 0;
    //     if (memo[n] != -1)
    //         return memo[n];
    //     memo[n] = cost[n] + min(recur(cost, n + 1, memo), recur(cost, n + 2, memo));
    //     return memo[n];
    // }
    // int minCostClimbingStairs(vector<int> &cost)
    // {
    //     vector<int> memo(cost.size(), -1);
    //     return min(recur(cost, 0, memo), recur(cost, 1, memo));
    // }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];
        for (int i = 2; i < n; i++)
        {
            int curr = min(prev1 + cost[i], prev2 + cost[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
};