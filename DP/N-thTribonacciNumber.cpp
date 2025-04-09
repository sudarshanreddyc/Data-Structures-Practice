class Solution
{
public:
    int tribonacciMemo(int n, vector<int> &memo)
    {
        if (n == 0)
            memo[n] = 0;
        if (n == 1 || n == 2)
            memo[n] = 1;
        if (memo[n] != -1)
            return memo[n];

        memo[n] = tribonacciMemo(n - 1, memo) + tribonacciMemo(n - 2, memo) + tribonacciMemo(n - 3, memo);
        return memo[n];
    }
    int tribonacci(int n)
    {
        vector<int> memo(n + 1, -1);
        return tribonacciMemo(n, memo);
    }
};