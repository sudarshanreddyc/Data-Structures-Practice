class Solution
{
public:
    // int f(int i, int j,string s1, string s2, vector<vector<int>>& memo){
    //     if(i < 0 || j < 0) return 0;
    //     if(memo[i][j] != -1) return memo[i][j];
    //     if(s1[i] == s2[j]) memo[i][j] = 1 + f(i-1, j-1, s1, s2, memo);
    //     else memo[i][j] = max(f(i-1, j, s1, s2, memo), f(i, j-1, s1, s2, memo));
    //     return memo[i][j];
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
    //     return f(text1.length()-1, text2.length()-1,text1, text2, memo);
    // }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};