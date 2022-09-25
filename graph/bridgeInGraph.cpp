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

        if (!visited[nb])           // IF VISITED
        {
            dfsGetBridge(nb, node, time, adj, disc, low, visited, ans);         // CALL DFS
            low[node] = min(low[node], low[nb]);      // WHILE RETURNING BACK IF, NBR NODE HAS LESSER LOW VALUE, UPDATE IT

            if (low[nb] > disc[node])       //CONDITION FOR BRIDGE => IF LOW OF NBR SHOULD BE SMALLER THAN DISC OF NODE (MOSTLY DISC > LOW)
                ans.push_back({node, nb});
        }
        else            // VISITED .:. IT IS CONNECTED TO AN ANCESTOR NODE (BACKEDGE)
            low[node] = min(low[node], disc[nb]);   // GET MIN OF THE BACKEDGE/ANCESTOR NODE IN LOW[NODE] :: OTHER PATH EXISTS
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