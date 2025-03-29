class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        unordered_map<char, int> mp1, mp2;

        // Store the freq
        for (auto &ch : word1)
            mp1[ch]++;
        for (auto &ch : word2)
            mp2[ch]++;

        // Check if all the chars from first word are present in second, then only we can perform operations on them
        for (auto &pair : mp1)
        {
            if (mp2[pair.first] <= 0)
                return false;
        }
        vector<int> v1, v2;
        for (auto &pair : mp1)
            v1.push_back(pair.second);
        for (auto &pair : mp2)
            v2.push_back(pair.second);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2;
    }
};