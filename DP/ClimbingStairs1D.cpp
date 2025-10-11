class Solution
{
public:
    int recurDP(int n, int cur, vector<int> &memo)
    {
        if (cur > n)
            return 0;
        if (cur == n)
            return 1;
        if (memo[cur] != -1)
            return memo[cur];
        memo[cur] = recurDP(n, cur + 1, memo) + recurDP(n, cur + 2, memo);
        return memo[cur];
    }
    int climbStairs(int n)
    {
        vector<int> memo(n + 2, -1);
        return recurDP(n, 0, memo);
    }
};