class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        unordered_map<string, int> rows, columns;

        for (int i = 0; i < n; i++)
        {
            string s1 = "", s2 = "";
            for (int j = 0; j < n; j++)
            {
                s1 += to_string(grid[i][j]) + ',';
                s2 += to_string(grid[j][i]) + ',';
            }
            rows[s1]++;
            columns[s2]++;
        }
        int count = 0;
        for (auto &pair : rows)
        {
            if (columns.find(pair.first) != columns.end())
                count += pair.second * columns[pair.first];
        }
        return count;
    }
};