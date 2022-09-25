#include <unordered_map>
#include <list>
#include <climits>

void dfsGetBridge(int node, int parent, int &time, unordered_map<int, list<int>> &adj, vector<int> &disc,
                  vector<int> &low, vector<bool> &visited, vector<vector<int>> &ans)
{
    visited[node] = 1;
    disc[node] = time;
    low[node] = time++;

    for (auto nb : adj[node])
    {
        if (nb == parent)
            continue;

        if (!visited[nb])
        {
            dfsGetBridge(nb, node, time, adj, disc, low, visited, ans);
            low[node] = min(low[node], low[nb]);

            if (low[nb] > disc[node])
                ans.push_back({node, nb});
        }
        else
            low[node] = min(low[node], disc[nb]);
    }
}

void setadj(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    setadj(adj, edges);

    vector<int> disc(v, INT_MAX);
    vector<int> low(v, INT_MAX);
    vector<bool> visited(v, 0);

    vector<vector<int>> ans;
    int time = 0;

    for (int i = 0; i < v; i++)
        if (!visited[i])
            dfsGetBridge(i, -1, time, adj, disc, low, visited, ans);

    return ans;
}