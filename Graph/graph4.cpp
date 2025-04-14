#include <iostream>
#include <vector>

// Class representing a graph using an adjacency list
class Graph
{
    int numVertices;
    std::vector<std::vector<int>> adjList;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // Function to add an edge between two vertices
    void addEdge(int src, int dest)
    {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // For undirected graphs
    }


    void printGraph() const
    {
        for (int i = 0; i < numVertices; ++i)
        {
            std::cout << i;
            for (int neighbor : adjList[i])
            {
                std::cout << " -> " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{\
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
