#include <vector>

class FenwickTree {
private:
    std::vector<int> bit;  // Binary Indexed Tree
    int n;

    // Utility function to get the sum of the first `pos` elements
    int prefixSum(int pos) {
        int sum = 0;
        while (pos) {
            sum += bit[pos];
            pos -= pos & -pos;  // Go to the parent in the update tree
        }
        return sum;
    }

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    // Initialize from a list of values
    FenwickTree(const std::vector<int>& values) : FenwickTree(values.size()) {
        for (int i = 0; i < n; ++i) {
            update(i, values[i]);
        }
    }

    // Add `delta` to the value at position `pos`
    void update(int pos, int delta) {
        ++pos;  // 1-indexed
        while (pos <= n) {
            bit[pos] += delta;
            pos += pos & -pos;  // Go to the next in the update tree
        }
    }

    // Get the sum of the elements in the range [0, pos]
    int rangeSum(int pos) {
        return prefixSum(pos + 1);  // Make it inclusive and 1-indexed
    }

    // Get the sum of elements in the range [left, right]
    int rangeSum(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

