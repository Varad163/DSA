#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adjList;  // Adjacency list

public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Add edge (undirected)
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Comment this line for a directed graph
    }

    // Display graph
    void display() {
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " -> ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // BFS Traversal
    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // DFS Traversal
    void dfsHelper(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal: ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);  // Graph with 5 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.display();

    g.bfs(0);  // Perform BFS from node 0
    g.dfs(0);  // Perform DFS from node 0

    return 0;
}
