class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        if (n == 0)
            return 0;

        int l = 0, r = 0, maxLen = INT_MIN;
        vector<int> mpp(255, -1);
        while (r < n)
        {
            if (mpp[s[r]] != -1 && mpp[s[r]] >= l)
            {
                l = mpp[s[r]] + 1;
            }
            maxLen = max(maxLen, r - l + 1);
            mpp[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};