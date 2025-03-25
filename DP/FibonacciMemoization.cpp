class Solution
{
public:
    int fibMemo(int n, vector<int> &memo)
    {
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        else if (memo[n] != -1)
            return memo[n];
        memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
        return memo[n];
    }
    int fib(int n)
    {
        vector<int> memo(n + 1, -1);
        return fibMemo(n, memo);
    }
};