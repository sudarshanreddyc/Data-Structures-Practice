class Solution
{
public:
    // DFS helper function for cycle detection
    bool dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, int parent)
    {
        visited[u] = true;

        for (int v : adj[u])
        {
            // If the neighbor is already visited and is not the parent, a cycle is found
            if (visited[v] && v != parent)
            {
                return true;
            }
            // If the neighbor is not visited, recurse on it
            if (!visited[v])
            {
                if (dfs(v, adj, visited, u))
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Main function to check if a cycle exists in the graph
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        // Form the adjacency list from the edges
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false); // To track visited nodes

        // Check each component of the graph (in case of disconnected components)
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            { // Start DFS only if the node is unvisited
                if (dfs(i, adj, visited, -1))
                {
                    return true; // Cycle detected
                }
            }
        }

        return false; // No cycle found
    }
};
