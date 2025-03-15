class Solution
{
public:
    vector<vector<int>> dp;
    bool isSafe(int i, int j, int m, int n)
    {
        return i < m && j < n;
    }

    int recurMove(int i, int j, int m, int n)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int down = 0, right = 0;
        // Instead of down, right & isSafe we can also add one base condition for out of bounds
        // if(i >= m || j >= n) return 0;
        // dp[i][j] = recurMove(i+1, j, m, n) + recurMove(i, j+1, m, n);
        if (isSafe(i + 1, j, m, n))
        {
            down = recurMove(i + 1, j, m, n);
        }
        if (isSafe(i, j + 1, m, n))
        {
            right = recurMove(i, j + 1, m, n);
        }
        dp[i][j] = down + right;
        return dp[i][j];
    }
    int uniquePaths(int m, int n)
    {
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return recurMove(0, 0, m, n);
    }
};