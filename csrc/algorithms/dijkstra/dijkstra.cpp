#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Graph {
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(std::make_pair(dest, weight));
        // uncomment the following line if the graph is undirected
        // adjList[dest].push_back(std::make_pair(src, weight));
    }

    void dijkstra(int src) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>> pq;

        std::vector<int> dist(numVertices, std::numeric_limits<int>::max());

        pq.push(std::make_pair(0, src));
        dist[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& i : adjList[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }

        printSolution(dist);
    }

    void printSolution(const std::vector<int>& dist) {
        std::cout << "Vertex Distance from Source" << std::endl;
        for (int i = 0; i < numVertices; ++i)
            std::cout << i << " \t\t " << dist[i] << std::endl;
    }
};

int main() {
    Graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

    return 0;
}
