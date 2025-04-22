class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0, r = 0, maxLen = INT_MIN, maxFreq = INT_MIN;
        vector<int> freq(26, 0);
        while (r < s.length())
        {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if (r - l + 1 - maxFreq > k)
            { // while(r-l+1-maxFreq > k) len of substring - maxFreq gives you the no of conversions required.
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(r - l + 1, maxLen);
            r++;
        }

        return maxLen;
    }
};