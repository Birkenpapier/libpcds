#include "binary_tree.hpp"
/**
 * Definition for a binary tree node.
 * class BTNode {
 *     public:
 *         BTNode*  lNode;
 *         BTNode*  rNode;
 *         int data;
 * 
 *         // insert new data
 *         BTNode(int val) : data(val), lNode(nullptr), rNode(nullptr) {}
 * };
 */

int main() {
    BTree btree;

    btree.insert(5);
    btree.insert(3);
    btree.insert(6);
    btree.insert(8);
    btree.insert(9);
    btree.insert(2);
    btree.insert(1);

    std::cout << "in order traversal" << std::endl;
    btree.inOrder();

    int valToSearch = 1;
    std::cout << "looking for " << valToSearch << ": "
        << (btree.search(valToSearch) ? "found" : "not found") << std::endl;

    valToSearch = 10;
    std::cout << "looking for " << valToSearch << ": "
        << (btree.search(valToSearch) ? "found" : "not found") << std::endl;

    return 0;
}