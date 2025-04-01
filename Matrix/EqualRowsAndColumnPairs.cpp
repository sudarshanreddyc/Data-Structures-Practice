class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> gridTranspose(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                gridTranspose[i][j] = grid[j][i];
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i] == gridTranspose[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};