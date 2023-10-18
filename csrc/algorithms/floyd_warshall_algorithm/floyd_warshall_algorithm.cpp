#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class FloydWarshallSolver {
public:
    FloydWarshallSolver(vector<vector<int>> matrix) : matrix(matrix) {}

    void findShortestPaths() {
        initializeData();
        computeShortestPaths();
        displayShortestPaths();
    }

private:
    vector<vector<int>> matrix;
    vector<vector<int>> distances;
    vector<vector<int>> routes;

    void initializeData() {
        int n = matrix.size();
        distances.resize(n, vector<int>(n));
        routes.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distances[i][j] = matrix[i][j];

                if (i == j) routes[i][j] = 0;
                else if (distances[i][j] != INT_MAX) routes[i][j] = i;
                else routes[i][j] = -1;
            }
        }
    }

    void computeShortestPaths() {
        int n = matrix.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX 
                        && distances[i][k] + distances[k][j] < distances[i][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                        routes[i][j] = routes[k][j];
                    }
                }
                if (distances[i][i] < 0) {
                    cout << "Detected negative-weight cycle!";
                    return;
                }
            }
        }
    }

    void displayShortestPaths() {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i && routes[i][j] != -1) {
                    cout << "Shortest path from " << i << " to " << j << ": ["
                         << i << ", ";
                    displayPath(i, j);
                    cout << j << "]" << endl;
                }
            }
        }
    }

    void displayPath(int start, int end) {
        if (routes[start][end] == start) return;
        displayPath(start, routes[start][end]);
        cout << routes[start][end] << ", ";
    }
};

int main() {
    int INF = INT_MAX;

    vector<vector<int>> graph = {
        {8, 9, -4, INF},
        {1, INF, 5, INF},
        {INF,2, 0, INF},
        {INF, -2, INF, 0}
    };

    FloydWarshallSolver solver(graph);
    solver.findShortestPaths();

    return 0;
}
