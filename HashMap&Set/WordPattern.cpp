class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mapPW;
        unordered_map<string, char> mapWP;

        vector<string> words;
        stringstream ss(s);

        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
            return false;
        for (int i = 0; i < pattern.length(); i++)
        {
            if (mapPW.count(pattern[i]))
            {
                if (mapPW[pattern[i]] != words[i])
                    return false;
            }
            else if (mapWP.count(words[i]))
            {
                if (mapWP[words[i]] != pattern[i])
                    return false;
            }
            else
            {
                mapPW[pattern[i]] = words[i];
                mapWP[words[i]] = pattern[i];
            }
        }
        return true;
    }
};