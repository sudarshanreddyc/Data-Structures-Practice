class Solution
{
public:
    bool dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
    {
        visited[u] = true;
        recStack[u] = true;
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                if (dfs(v, adj, visited, recStack))
                    return true;
            }
            // Back edge found
            else if (recStack[v])
                return true;
        }
        // Backtrack
        recStack[u] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto &edge : prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                // Detected cycle
                if (dfs(i, adj, visited, recStack))
                    return false;
            }
        }

        return true;
    }
};