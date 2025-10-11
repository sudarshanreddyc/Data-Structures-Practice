class Solution
{
public:
    bool isSInDict(string cur, vector<string> &dict)
    {
        return find(dict.begin(), dict.end(), cur) != dict.end();
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int i = 0;
        string cur = "";
        int l = s.length();
        vector<bool> dp(l, false);
        while (i < l)
        {
            cur += s[i];
            if (isSInDict(cur, wordDict))
            {
                dp[i] = true;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    if (dp[j] && isSInDict(s.substr(j + 1, i - j), wordDict))
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
            i++;
        }
        if (dp[l - 1])
            return true;
        return false;
    }
};