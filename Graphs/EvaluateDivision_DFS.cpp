class Solution
{
public:
    double dfs(string src, string tar, unordered_set<string> &visited, unordered_map<string, unordered_map<string, double>> &mp, double cur)
    {
        // if query is not found in map
        if (mp.find(src) == mp.end() || mp.find(tar) == mp.end())
            return -1;
        // if numerator and denominator is same
        if (src == tar)
            return 1;
        // if denominator is directly connected to numerator then return directly with multiplication.
        if (mp[src].find(tar) != mp[src].end())
            return cur * mp[src][tar];
        visited.insert(src);
        for (auto &adj : mp[src])
        {
            if (visited.find(adj.first) == visited.end())
            {
                double res = dfs(adj.first, tar, visited, mp, cur * adj.second);
                if (res != -1)
                    return res;
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, unordered_map<string, double>> mp;
        int i = 0;
        for (const auto &eq : equations)
        {
            mp[eq[0]][eq[1]] = values[i];
            mp[eq[1]][eq[0]] = 1 / values[i];
            i++;
        }

        vector<double> res;
        for (const auto &q : queries)
        {
            unordered_set<string> visited;
            double cur = 1;
            res.push_back(dfs(q[0], q[1], visited, mp, cur));
        }
        return res;
    }
};