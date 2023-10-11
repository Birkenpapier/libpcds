#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, std::vector<int>(n));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    Matrix A11(n/2, std::vector<int>(n/2)), A12(n/2, std::vector<int>(n/2)), A21(n/2, std::vector<int>(n/2)), A22(n/2, std::vector<int>(n/2));
    Matrix B11(n/2, std::vector<int>(n/2)), B12(n/2, std::vector<int>(n/2)), B21(n/2, std::vector<int>(n/2)), B22(n/2, std::vector<int>(n/2));

    // Divide matrices A and B into 4 sub-matrices each
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+n/2];
            A21[i][j] = A[i+n/2][j];
            A22[i][j] = A[i+n/2][j+n/2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+n/2];
            B21[i][j] = B[i+n/2][j];
            B22[i][j] = B[i+n/2][j+n/2];
        }
    }

    Matrix P1 = strassen(A11, subtract(B12, B22));
    Matrix P2 = strassen(add(A11, A12), B22);
    Matrix P3 = strassen(add(A21, A22), B11);
    Matrix P4 = strassen(A22, subtract(B21, B11));
    Matrix P5 = strassen(add(A11, A22), add(B11, B22));
    Matrix P6 = strassen(subtract(A12, A22), add(B21, B22));
    Matrix P7 = strassen(subtract(A11, A21), add(B11, B12));

    // Calculate the 4 sub-matrices of the result
    Matrix C11 = add(subtract(add(P5, P4), P2), P6);
    Matrix C12 = add(P1, P2);
    Matrix C21 = add(P3, P4);
    Matrix C22 = subtract(subtract(add(P5, P1), P3), P7);

    // Combine the 4 sub-matrices to get the final result
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j+n/2] = C12[i][j];
            C[i+n/2][j] = C21[i][j];
            C[i+n/2][j+n/2] = C22[i][j];
        }
    }

    return C;
}

int main() {
    // Example matrices
    Matrix A = {
        {1, 2},
        {3, 4}
    };

    Matrix B = {
        {2, 0},
        {0, 2}
    };

    Matrix C = strassen(A, B);

    for (const auto& row : C) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
