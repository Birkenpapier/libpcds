#include <vector>
#include <algorithm>
#include <iostream>

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class KDTree {
private:
    struct Node {
        Point point;
        Node* left;
        Node* right;
        Node(const Point& p) : point(p), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build(std::vector<Point>& points, int depth = 0) {
        if (points.empty()) return nullptr;

        // Alternate axis at each depth level
        int axis = depth % 2;

        // Sort based on current axis
        if (axis == 0) {
            std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
                return a.x < b.x;
            });
        } else {
            std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
                return a.y < b.y;
            });
        }

        // Median point will be the root of this subtree
        int median = points.size() / 2;
        Node* node = new Node(points[median]);

        // Split points into two halves and build left and right subtrees
        std::vector<Point> leftPoints(points.begin(), points.begin() + median);
        std::vector<Point> rightPoints(points.begin() + median + 1, points.end());
        node->left = build(leftPoints, depth + 1);
        node->right = build(rightPoints, depth + 1);

        return node;
    }

public:
    KDTree(const std::vector<Point>& points) {
        std::vector<Point> mutablePoints = points;
        root = build(mutablePoints);
    }

    ~KDTree() {
        // Destructor should ideally delete nodes to free memory.
        // For simplicity, this is omitted here, but should be implemented for a production version.
    }

    // Additional functions like nearest neighbor, range queries, etc. can be added here.
};

int main() {
    std::vector<Point> points = {
        {2, 3},
        {5, 4},
        {9, 6},
        {4, 7},
        {8, 1},
        {7, 2}
    };

    KDTree tree(points);
    
    // For this basic version, there's no output or query functionality.
    // In a more advanced version, you could add methods to query the tree,
    // find nearest neighbors, etc.

    return 0;
}
