#include "trie.hpp"

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
