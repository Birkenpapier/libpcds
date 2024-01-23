#include "a_star.hpp"

int main() {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    Node start(0, 0);
    Node end(4, 4);

    auto path = aStar(grid, start, end);
    for (auto& node : path) {
        std::cout << "(" << node.x << "," << node.y << ") ";
    }

    return 0;
}
