#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

const int MAX_LEVEL = 4;

int randomLevel() {
    int level = 1;
    while ((rand() % 2) && level < MAX_LEVEL) {
        level++;
    }
    return level;
}

class Node {
public:
    int value;
    std::vector<Node*> forward;

    Node(int value, int level) : value(value), forward(level, nullptr) {}
};

class SkipList {
private:
    int maxLevel;
    Node* header;
    int level;

public:
    SkipList() : maxLevel(MAX_LEVEL), level(0) {
        int headKey = std::numeric_limits<int>::min();
        header = new Node(headKey, maxLevel);
    }

    ~SkipList() {
        deleteList();
    }

    void insert(int value) {
        std::vector<Node*> update(maxLevel, nullptr);
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        current = current->forward[0];

        if (current == nullptr || current->value != value) {
            int randomLvl = randomLevel();

            if (randomLvl > level) {
                for (int i = level + 1; i < randomLvl; i++) {
                    update[i] = header;
                }

                level = randomLvl;
            }

            Node* newNode = new Node(value, randomLvl);
            for (int i = 0; i < randomLvl; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    bool search(int value) {
        Node* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] && current->forward[i]->value < value) {
                current = current->forward[i];
            }
        }

        current = current->forward[0];

        return current && current->value == value;
    }

    void display() {
        for (int i = 0; i <= level; i++) {
            Node* node = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (node != nullptr) {
                std::cout << node->value << " ";
                node = node->forward[i];
            }
            std::cout << std::endl;
        }
    }

private:
    void deleteList() {
        Node* current = header;
        while (current) {
            Node* temp = current;
            current = current->forward[0];
            delete temp;
        }
    }
};

int main() {
    // seed random number generator
    srand((unsigned)time(nullptr));

    SkipList list;

    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(21);
    list.insert(25);

    list.display();

    std::cout << "Search for 19: " << (list.search(19) ? "Found" : "Not found") << std::endl;

    return 0;
}
