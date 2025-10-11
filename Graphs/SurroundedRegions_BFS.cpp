class Solution
{
public:
    bool isBoundary(int row, int col, int n, int m)
    {
        return row == 0 || row == n - 1 || col == 0 || col == m - 1;
    }
    bool bfs(vector<vector<char>> &board, int row, int col, vector<vector<bool>> &visited)
    {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for (auto pr : directions)
            {
                int nRow = row + pr.first;
                int nCol = col + pr.second;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && board[nRow][nCol] == 'O')
                {
                    visited[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
        return false;
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && board[row][col] == 'O' && isBoundary(row, col, n, m))
                {
                    queue<pair<int, int>> placesToFill;
                    bfs(board, row, col, visited);
                }
            }
        }
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
            }
        }
    }
};