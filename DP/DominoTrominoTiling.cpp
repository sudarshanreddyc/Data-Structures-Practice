class Solution
{
public:
    // int numTilings(int n) {
    //     const int MOD = 1e9 + 7;
    //     if (n == 0) return 1;
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;

    //     vector<long long> dp(n + 1);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     dp[2] = 2;

    //     for (int i = 3; i <= n; ++i) {
    //         dp[i] = (2 * dp[i - 1] + dp[i - 3]) % MOD;
    //     }

    //     return dp[n];
    // }
    int numTilings(int n)
    {
        const int MOD = 1000000007;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        long a = 1;
        long b = 2;
        long c = 5;
        long d;

        for (int i = 4; i <= n; ++i)
        {
            d = (2 * c + a) % MOD;
            a = b;
            b = c;
            c = d;
        }

        return c;
    }
};