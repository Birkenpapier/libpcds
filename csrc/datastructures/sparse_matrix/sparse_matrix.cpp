#include <iostream>
#include <map>
#include <utility>

class SparseMatrix {
private:
    std::map<std::pair<int, int>, double> elements;
    int rows, cols;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void insert(int row, int col, double value) {
        if (value != 0) {
            elements[{row, col}] = value;
        }
    }

    double getValue(int row, int col) const {
        auto it = elements.find({row, col});
        if (it != elements.end()) {
            return it->second;
        }
        return 0;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                auto it = elements.find({i, j});
                if (it != elements.end()) {
                    std::cout << it->second << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix matrix(4, 5);

    matrix.insert(0, 0, 5);
    matrix.insert(0, 4, 10);
    matrix.insert(2, 2, 3);
    matrix.insert(3, 1, 15);

    std::cout << "Sparse Matrix:" << std::endl;
    matrix.display();

    int row = 2, col = 2;
    std::cout << "Value at (" << row << ", " << col << "): " << matrix.getValue(row, col) << std::endl;

    return 0;
}
