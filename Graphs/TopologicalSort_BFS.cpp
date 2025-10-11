class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        // Build adj matrix and find indegree for each vertex
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // push all the vertices with indegree as 0 to queue
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            // Decrease the indegree of all the vertices that are coming from cur
            for (auto &u : adj[cur])
            {
                indegree[u]--;
                if (indegree[u] == 0)
                    q.push(u);
            }
        }
        return topo;
    }
};