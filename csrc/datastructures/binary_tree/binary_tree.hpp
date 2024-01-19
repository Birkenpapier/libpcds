#include <unordered_map>

class BTNode {
    public:
        std::unordered_map<char, BTNode*> LNode;
        std::unordered_map<char, BTNode*> RNode;
        int data;
};
