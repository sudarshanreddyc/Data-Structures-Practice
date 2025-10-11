class Solution
{
public:
    // Pass grid by reference to avoid unnecessary copying
    void dfs(vector<vector<char>> &grid, int row, int col, vector<vector<bool>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;

        // Explore all 8 possible directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dr, dc] : directions)
        {
            int nRow = row + dr;
            int nCol = col + dc;
            // Check if the new row and column are within bounds and the cell is land ('1') and unvisited
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == '1' && !visited[nRow][nCol])
            {
                dfs(grid, nRow, nCol, visited); // Recursively visit the neighbor
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0; // Edge case: empty grid
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false)); // To track visited nodes
        int count = 0;

        // Traverse each cell in the grid
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                // If it's an unvisited land cell ('1'), start DFS to mark all connected cells
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    count++;                      // Increment island count
                    dfs(grid, row, col, visited); // Mark the entire island
                }
            }
        }
        return count; // Return the total number of islands
    }
};
