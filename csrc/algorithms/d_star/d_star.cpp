#include <iostream>
#include <queue>
#include <map>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

struct Node {
    int x, y;
    float g;
    float rhs;
    Node(int x, int y) : x(x), y(y), g(INFINITY), rhs(INFINITY) {}
    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Node& other) const {
        return !(*this == other);
    }
    bool operator<(const Node& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }    
};

namespace std {
    template <>
    struct hash<Node> {
        size_t operator()(const Node& node) const {
            return hash<int>()(node.x) ^ hash<int>()(node.y);
        }
    };
}

struct Compare {
    bool operator()(const pair<float, Node>& a, const pair<float, Node>& b) const {
        return a.first > b.first;
    }
};

class DStar {
private:
    map<Node, vector<Node>> graph;
    priority_queue<pair<float, Node>, vector<pair<float, Node>>, Compare> openList;
    map<Node, float> gValues;
    map<Node, float> rhsValues;
    map<Node, bool> validNode;
    Node start;
    Node goal;

    float heuristic(const Node& a, const Node& b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    void initialize() {
        for (auto& node : graph) {
            gValues[node.first] = INFINITY;
            rhsValues[node.first] = INFINITY;
            validNode[node.first] = true;
        }
        rhsValues[goal] = 0;
        openList.push(make_pair(heuristic(goal, start), goal));
    }

    void updateNode(const Node& node) {
        if (node != goal) {
            float minRhs = INFINITY;
            for (auto& successor : graph[node]) {
                float tmpRhs = gValues[successor] + heuristic(node, successor);
                if (tmpRhs < minRhs) minRhs = tmpRhs;
            }
            rhsValues[node] = minRhs;
        }

        validNode[node] = false;

        if (gValues[node] != rhsValues[node]) {
            validNode[node] = true;
            openList.push(make_pair(rhsValues[node] + heuristic(start, node), node));
        }
    }

    void computeShortestPath() {
        while (!openList.empty()) {
            Node currentNode = openList.top().second;
            openList.pop();

            if (!validNode[currentNode]) continue;

            if (gValues[currentNode] > rhsValues[currentNode]) {
                gValues[currentNode] = rhsValues[currentNode];
            } else {
                gValues[currentNode] = INFINITY;
                updateNode(currentNode);
            }

            for (auto& successor : graph[currentNode]) {
                updateNode(successor);
            }

            if (openList.empty() || (openList.top().first >= gValues[start] && rhsValues[start] == gValues[start])) break;
        }
    }

public:
    DStar(map<Node, vector<Node>>& graph, Node start, Node goal) : graph(graph), start(start), goal(goal) {
        initialize();
    }

    void replan() {
        computeShortestPath();
    }

    float getCost() {
        return gValues[start];
    }
};

int main() {
    Node n1(0, 0), n2(1, 0), n3(1, 1);
    map<Node, vector<Node>> graph = {
        {n1, {n2, n3}},
        {n2, {n1, n3}},
        {n3, {n1, n2}}
    };

    DStar dstar(graph, n1, n3);
    dstar.replan();

    cout << "Cost from start to goal: " << dstar.getCost() << endl;

    return 0;
}
