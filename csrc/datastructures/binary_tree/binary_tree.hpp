#include <iostream>

class BTNode {
    public:
        BTNode*  lNode;
        BTNode*  rNode;
        int data;

        // insert new data
        BTNode(int val) : data(val), lNode(nullptr), rNode(nullptr) {}
};

class BTree {
    private:
        BTNode* root;

        BTNode* insert(BTNode* n, int val) {
            if(n == nullptr) {
                return new BTNode(val);
            }

            if(val < n->data) {
                n->lNode = insert(n->lNode, val);
            } else {
                n->rNode = insert(n->rNode, val);   
            }

            return n;
        }

        void inOrder(BTNode* n) {
            if(n != nullptr) {
                inOrder(n->lNode);
                std::cout << n->data << " ";
                inOrder(n->rNode);
            }
        }

        bool search(BTNode* n, int val) {
            if(n == nullptr) {
                return false;
            }
            if(n->data == val) {
                return true;
            }
            if(val < n->data) {
                return search(n->lNode, val);
            } else {
                return search(n->rNode, val);
            }
        }

        void free(BTNode* n) {
            if(n) {
                free(n->lNode);
                free(n->rNode);
                delete n;
            }
        }

    public:
        BTree() : root(nullptr) {}

        ~BTree() {
            free(root);
        }

        void insert(int val) {
            root = insert(root, val);
        }

        void inOrder() {
            inOrder(root);
            std::cout << std::endl;
        }

        bool search(int val) {
            return search(root, val);
        }
};
