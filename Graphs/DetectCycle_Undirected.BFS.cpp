class Solution
{
public:
    // BFS helper function for cycle detection
    bool bfs(int V, vector<vector<int>> &adj, int source, vector<bool> &visited)
    {
        queue<pair<int, int>> q; // Queue stores {node, parent}

        q.push({source, -1}); // Start with the source node and -1 as parent
        visited[source] = true;

        while (!q.empty())
        {
            int u = q.front().first;       // Current node
            int parent = q.front().second; // Parent of the current node
            q.pop();

            // Traverse all neighbors of u
            for (int v : adj[u])
            {
                // If the neighbor is visited and is not the parent, a cycle is detected
                if (visited[v] && v != parent)
                {
                    return true; // Cycle detected
                }

                // If the neighbor is not visited, mark it as visited and push it to the queue
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, u}); // Push the neighbor with the current node as its parent
                }
            }
        }

        return false; // No cycle detected
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
            { // Start BFS only if the node is unvisited
                if (bfs(V, adj, i, visited))
                {
                    return true; // Cycle detected
                }
            }
        }

        return false; // No cycle found
    }
};
