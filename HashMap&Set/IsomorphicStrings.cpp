class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> mapST, mapTS;
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            if (mapST.find(s[i]) != mapST.end())
            {
                if (mapST[s[i]] != t[i])
                    return false;
            }
            else if (mapTS.find(t[i]) != mapTS.end())
            {
                if (mapTS[t[i]] != s[i])
                    return false;
            }
            else
            {
                mapST[s[i]] = t[i];
                mapTS[t[i]] = s[i];
            }
        }
        return true;
    }
};