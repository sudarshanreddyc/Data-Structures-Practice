class Solution
{
public:
    void dfs(vector<vector<int>> adj, int s, vector<bool> &visited)
    {
        visited[s] = true;
        for (auto &u : adj[s])
        {
            if (!visited[u])
            {
                dfs(adj, u, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        vector<bool> visited(V + 1, false);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (isConnected[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(adj, i, visited);
            }
        }

        return count;
    }
};