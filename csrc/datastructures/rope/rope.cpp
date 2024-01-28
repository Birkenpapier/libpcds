#include <iostream>
#include <string>
#include <memory>

class RopeNode {
public:
    std::unique_ptr<RopeNode> left, right;
    std::string str;
    int weight;

    RopeNode(const std::string &s) : str(s), weight(s.length()) {}
};

class Rope {
private:
    std::unique_ptr<RopeNode> root;

    void concat(std::unique_ptr<RopeNode>& node, std::unique_ptr<RopeNode>& other) {
        if (!node) {
            node = std::move(other);
        } else {
            std::unique_ptr<RopeNode> newRoot = std::make_unique<RopeNode>("");
            newRoot->left = std::move(node);
            newRoot->right = std::move(other);
            newRoot->weight = newRoot->left->weight + (newRoot->right ? newRoot->right->weight : 0);
            node = std::move(newRoot);
        }
    }

    void insert(std::unique_ptr<RopeNode>& node, int pos, const std::string &s) {
        if (!node) {
            node = std::make_unique<RopeNode>(s);
        } else if (pos < node->weight) {
            insert(node->left, pos, s);
        } else {
            insert(node->right, pos - node->weight, s);
        }
        node->weight = node->left->weight + (node->right ? node->right->weight : 0);
    }

    void print(const std::unique_ptr<RopeNode>& node) const {
        if (!node) return;
        print(node->left);
        std::cout << node->str;
        print(node->right);
    }

public:
    Rope() {}

    void insert(int pos, const std::string &s) {
        insert(root, pos, s);
    }

    void concat(Rope &other) {
        concat(root, other.root);
    }

    void print() const {
        print(root);
        std::cout << std::endl;
    }
};

int main() {
    Rope rope1;
    rope1.insert(0, "Hello ");
    Rope rope2;
    rope2.insert(0, "World!");

    rope1.concat(rope2);
    rope1.print();

    return 0;
}
