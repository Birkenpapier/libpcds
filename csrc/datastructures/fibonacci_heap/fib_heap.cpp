#include <iostream>
#include <memory>
#include <vector>
#include <cmath>

template <typename T>
class FibonacciHeap;

template <typename T>
struct Node {
    T value;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
    std::shared_ptr<Node<T>> child;
    std::shared_ptr<Node<T>> parent;
    bool marked;
    int degree;

    Node(T val) : value(val), degree(0), marked(false), parent(nullptr), child(nullptr) {
        left = right = std::shared_ptr<Node<T>>(this);
    }
};

template <typename T>
class FibonacciHeap {
private:
    std::shared_ptr<Node<T>> min;
    int nH;

    void consolidate() {
        if (!min) return;

        int arraySize = std::floor(std::log2(nH)) + 1;
        std::vector<std::shared_ptr<Node<T>>> degreeTable(arraySize);

        std::vector<std::shared_ptr<Node<T>>> rootList;
        auto current = min;
        do {
            rootList.push_back(current);
            current = current->right;
        } while (current != min);

        for (auto &w : rootList) {
            auto x = w;
            int d = x->degree;
            while (degreeTable[d]) {
                auto y = degreeTable[d];
                if (x->value > y->value) std::swap(x, y);
                link(y, x);
                degreeTable[d] = nullptr;
                d++;
            }
            degreeTable[d] = x;
        }

        min = nullptr;
        for (auto &w : degreeTable) {
            if (w) {
                if (!min || w->value < min->value) {
                    min = w;
                }
            }
        }
    }

    void link(std::shared_ptr<Node<T>> y, std::shared_ptr<Node<T>> x) {
        y->left->right = y->right;
        y->right->left = y->left;
        y->parent = x;

        if (!x->child) {
            x->child = y;
            y->right = y;
            y->left = y;
        } else {
            y->left = x->child;
            y->right = x->child->right;
            x->child->right = y;
            y->right->left = y;
        }

        x->degree++;
        y->marked = false;
    }

public:
    FibonacciHeap() : min(nullptr), nH(0) {}

    void insert(const T &value) {
        auto node = std::make_shared<Node<T>>(value);
        if (!min) {
            min = node;
        } else {
            min->left->right = node;
            node->right = min;
            node->left = min->left;
            min->left = node;
            if (value < min->value) {
                min = node;
            }
        }
        nH++;
    }

    std::shared_ptr<Node<T>> findMin() const {
        return min;
    }

    void merge(FibonacciHeap &other) {
        if (!other.min) return;

        if (!min) {
            min = other.min;
        } else {
            min->right->left = other.min->left;
            other.min->left->right = min->right;
            min->right = other.min;
            other.min->left = min;
            if (other.min->value < min->value) {
                min = other.min;
            }
        }
        nH += other.nH;
        other.min.reset();
        other.nH = 0;
    }
};

int main() {
    FibonacciHeap<int> heap1;
    heap1.insert(10);
    heap1.insert(2);
    heap1.insert(15);

    FibonacciHeap<int> heap2;
    heap2.insert(23);
    heap2.insert(7);

    heap1.merge(heap2);

    auto min = heap1.findMin();
    if (min) {
        std::cout << "Minimum value: " << min->value << std::endl;
    }

    return 0;
}
