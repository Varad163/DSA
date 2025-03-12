#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

bool isConnected(int N, vector<vector<int>> &adj)
{
    vector<bool> visited(N, false);

    // Start DFS from the first node (assuming nodes are 0-based)
    dfs(0, adj, visited);

    // Check if all nodes were visited
    for (bool v : visited)
    {
        if (!v)
            return false;
    }
    return true;
}

int main()
{
    int N, M;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> M;

    vector<vector<int>> adj(N);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    if (isConnected(N, adj))
    {
        cout << "The graph is connected." << endl;
    }
    else
    {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
