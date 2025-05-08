class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto &str : strs)
        {
            string strSorted = str;
            sort(strSorted.begin(), strSorted.end());
            mp[strSorted].push_back(str);
        }
        vector<vector<string>> res;
        for (auto &group : mp)
        {
            res.push_back(group.second);
        }

        return res;
    }
};