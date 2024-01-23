#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Node {
    int x, y;
    float f, g, h;
    Node* parent;

    Node(int _x, int _y, Node* _parent = nullptr) : x(_x), y(_y), f(0), g(0), h(0), parent(_parent) {}

    bool operator == (const Node& other) const {
        return x == other.x && y == other.y;
    }
};

using NodePtr = Node*;

float heuristic(const Node& start, const Node& end) {
    return std::abs(start.x - end.x) + std::abs(start.y - end.y);
}

std::vector<NodePtr> getSuccessors(NodePtr node, const std::vector<std::vector<int>>& grid) {
    std::vector<NodePtr> successors;

    const int dirs[4][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    for (int i = 0; i < 4; i++) {
        int newX = node->x + dirs[i][0], newY = node->y + dirs[i][1];

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == 0) {
            successors.push_back(new Node(newX, newY, node));
        }
    }

    return successors;
}

std::vector<Node> aStar(const std::vector<std::vector<int>>& grid, Node start, Node end) {
    std::vector<NodePtr> openList;
    std::vector<NodePtr> closedList;

    NodePtr startNode = new Node(start.x, start.y);
    NodePtr endNode = new Node(end.x, end.y);

    openList.push_back(startNode);

    while (!openList.empty()) {
        NodePtr current = *std::min_element(openList.begin(), openList.end(), [](NodePtr a, NodePtr b) {
            return a->f < b->f;
        });

        if (*current == *endNode) {
            std::vector<Node> path;
            while (current != nullptr) {
                path.push_back(*current);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());

            // Clean up dynamically allocated nodes
            for (auto node : openList) delete node;
            for (auto node : closedList) delete node;

            return path;
        }

        openList.erase(std::remove(openList.begin(), openList.end(), current), openList.end());
        closedList.push_back(current);

        for (auto successor : getSuccessors(current, grid)) {
            if (std::find_if(closedList.begin(), closedList.end(), [&](NodePtr node) {
                    return *node == *successor;
                }) != closedList.end()) {
                delete successor;
                continue;
            }

            successor->g = current->g + 1;
            successor->h = heuristic(*successor, *endNode);
            successor->f = successor->g + successor->h;

            if (std::find_if(openList.begin(), openList.end(), [&](NodePtr node) {
                    return *node == *successor && node->g <= successor->g;
                }) != openList.end()) {
                delete successor;
                continue;
            }

            openList.push_back(successor);
        }
    }

    return {};  // No path found
}
