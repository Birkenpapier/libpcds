#include <vector>

class SegmentTree {
private:
    std::vector<int> tree;
    std::vector<int> arr;
    int n;

    // Utility function to build the tree
    void build(int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    int query(int idx, int left, int right, int qLeft, int qRight) {
        if (qLeft > qRight) return 0;
        if (qLeft == left && qRight == right) return tree[idx];
        int mid = left + (right - left) / 2;
        return query(2 * idx, left, mid, qLeft, std::min(qRight, mid))
             + query(2 * idx + 1, mid + 1, right, std::max(qLeft, mid + 1), qRight);
    }

    void update(int idx, int left, int right, int pos, int newValue) {
        if (left == right) {
            arr[pos] = newValue;
            tree[idx] = newValue;
            return;
        }

        int mid = left + (right - left) / 2;
        if (pos <= mid) update(2 * idx, left, mid, pos, newValue);
        else update(2 * idx + 1, mid + 1, right, pos, newValue);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

public:
    SegmentTree(const std::vector<int>& inputArr) : arr(inputArr) {
        n = arr.size();
        tree.resize(4 * n);  // Maximum size needed
        build(1, 0, n - 1);
    }

    // Public function to query range sum
    int rangeSum(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }

    // Public function to update value at position `pos`
    void updateValue(int pos, int newValue) {
        update(1, 0, n - 1, pos, newValue);
    }
};
