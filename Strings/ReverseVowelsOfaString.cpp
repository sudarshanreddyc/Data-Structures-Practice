class Solution
{
public:
    bool isVowel(char c)
    {
        unordered_set<char> vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        return vowels.find(c) != vowels.end();
    }
    string reverseVowels(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (isVowel(s[l]) && isVowel(s[r]))
            {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            if (!isVowel(s[l]))
                l++;
            if (!isVowel(s[r]))
                r--;
        }
        return s;
    }
};