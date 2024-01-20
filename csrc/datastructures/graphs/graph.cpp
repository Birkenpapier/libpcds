#include <iostream>
#include <list>
#include <vector>

class Graph {
private:
    int vertices;
    std::vector<std::list<int>> adjList;

public:
    Graph(int v) : vertices(v), adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void display() {
        for (int i = 0; i < vertices; ++i) {
            std::cout << i << ": ";
            for (int vertex : adjList[i]) {
                std::cout << vertex << " -> ";
            }
            std::cout << "NULL" << std::endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Graph adjacency list:" << std::endl;
    g.display();

    return 0;
}
