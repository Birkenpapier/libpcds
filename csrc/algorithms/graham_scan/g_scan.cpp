#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

struct Point {
    int x, y;
};

Point p0;

int distSq(const Point &p1, const Point &p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(const Point &p, const Point &q, const Point &r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

void swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

Point nextToTop(std::stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

bool compare(const Point &p1, const Point &p2) {
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p2) >= distSq(p0, p1);
    return (o == 2);
}

void convexHull(std::vector<Point> points) {
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < points.size(); i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);

    p0 = points[0];
    std::sort(points.begin() + 1, points.end(), compare);

    int m = 1;
    for (int i = 1; i < points.size(); i++) {
        while (i < points.size() - 1 && orientation(p0, points[i],
                points[i + 1]) == 0)
            i++;

        points[m] = points[i];
        m++;
    }

    if (m < 3) return;

    std::stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++) {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    while (!S.empty()) {
        Point p = S.top();
        std::cout << "(" << p.x << ", " << p.y << ")" << std::endl;
        S.pop();
    }
}

int main() {
    std::vector<Point> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                                 {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    convexHull(points);

    return 0;
}
