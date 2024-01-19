#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}

    // recursive function to collect words in the trie
    void toString(std::stringstream& out, const std::string& word) const {
        if (isEndOfWord) {
            out << word << std::endl;
        }
        for (const auto& child : children) {
            child.second->toString(out, word + child.first);
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        clear(root);
    }

    void insert(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new TrieNode();
            }
            currentNode = currentNode->children[ch];
        }
        currentNode->isEndOfWord = true;
    }

    bool search(const std::string &word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }

    std::string toString() const {
        std::stringstream out;
        root->toString(out, "");
        return out.str();
    }

private:
    void clear(TrieNode* node) {
        for (auto& child : node->children) {
            clear(child.second);
        }
        delete node;
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");
    trie.insert("her");
    trie.insert("he");
    trie.insert("hero");

    std::cout << "Trie contents: " << std::endl;
    std::cout << trie.toString();

    std::string searchWord = "hello";
    std::cout << "Searching for \"" << searchWord << "\": "
              << (trie.search(searchWord) ? "found" : "not found") << std::endl;

    searchWord = "hell";
    std::cout << "Searching for \"" << searchWord << "\": "
              << (trie.search(searchWord) ? "found" : "not found") << std::endl;

    return 0;
}
