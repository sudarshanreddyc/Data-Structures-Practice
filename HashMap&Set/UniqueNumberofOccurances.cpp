class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for (int &num : arr)
        {
            mp[num]++;
        }
        for (auto &pair : mp)
        {
            st.insert(pair.second);
        }
        return st.size() == mp.size();
    }
};