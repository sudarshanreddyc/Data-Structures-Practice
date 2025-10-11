class Solution
{
public:
    pair<int, int> toRowCol(int s, int n)
    {
        int q = (s - 1) / n, r = (s - 1) % n;
        int row = n - 1 - q;
        int col = (q % 2 == 0) ? r : (n - 1 - r);
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        queue<pair<int, int>> q;
        int n = board.size();
        vector<int> visited(n * n + 1, false);

        auto [r, c] = toRowCol(1, n);
        int start = board[r][c] == -1 ? 1 : board[r][c];

        q.push({start, 0});
        visited[start] = true;

        while (!q.empty())
        {
            auto [start, cur] = q.front();
            q.pop();
            auto [r, c] = toRowCol(start, n);

            if (start == n * n)
                return cur;

            for (int j = 1; j <= 6 && j + start <= n * n; j++)
            {
                int nextStart = start + j;
                auto [rr, cc] = toRowCol(nextStart, n);

                if (board[rr][cc] != -1)
                {
                    nextStart = board[rr][cc];
                }

                if (nextStart == n * n)
                    return cur + 1;

                if (!visited[nextStart])
                {
                    visited[nextStart] = true;
                    q.push({nextStart, cur + 1});
                }
            }
        }
        return -1;
    }
};