#include <iostream>
#include <vector>
#include <limits>

// util function for printing the optimal parentheses placement
void printOptimalParens(const std::vector<std::vector<int>> &s, int i, int j) {
    if (i == j) {
        std::cout << "A" << i;
    } else {
        std::cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        std::cout << ")";
    }
}

// MatrixChainOrder function that implements the Matrix Chain Multiplication algorithm
void MatrixChainOrder(const std::vector<int> &p) {
    int n = p.size() - 1;
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            m[i][j] = std::numeric_limits<int>::max();
            for (int k = i; k < j; ++k) {

                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    std::cout << "Minimum number of multiplications is " << m[0][n - 1] << std::endl;
    std::cout << "Optimal Parenthesization is: ";
    printOptimalParens(s, 0, n - 1);
    std::cout << std::endl;
}

int main() {
    // array p[] represents the chain of matrices
    std::vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    MatrixChainOrder(p);

    return 0;
}
