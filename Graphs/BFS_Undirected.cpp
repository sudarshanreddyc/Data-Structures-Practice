class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int noOfVertices = adj.size();
        bool visited[noOfVertices];
        for (int i = 0; i < noOfVertices; i++)
        {
            visited[i] = false;
        }
        queue<int> v;
        vector<int> res;
        v.push(0);
        visited[0] = true;
        while (!v.empty())
        {
            int u = v.front();
            v.pop();
            res.push_back(u);
            for (int x : adj[u])
            {
                if (visited[x] == false)
                {
                    v.push(x);
                    visited[x] = true;
                }
            }
        }
        return res;
    }
};