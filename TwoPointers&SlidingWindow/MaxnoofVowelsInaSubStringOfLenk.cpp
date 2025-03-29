class Solution
{
public:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) // It can be solved using prefix sum too
    {
        int n = s.length();
        int maxCount = 0, count = 0;
        for (int i = 0; i < k; i++)
        {
            if (isVowel(s[i]))
                count++;
        }
        int left = 0, right = k;
        maxCount = count;
        while (right < n)
        {
            if (isVowel(s[right]))
                count++;
            if (isVowel(s[left]))
                count--;
            maxCount = max(maxCount, count);
            right++;
            left++;
        }
        return maxCount;
    }
};