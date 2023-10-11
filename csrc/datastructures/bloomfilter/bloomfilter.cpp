#include <vector>
#include <functional>
#include <iostream>

class BloomFilter {
private:
    std::vector<bool> bitset;
    int size;
    int numHashes;

    // Just some example hash functions. In a real-world scenario, you'd use more complex hash functions.
    std::hash<std::string> hash1;
    std::hash<std::size_t> hash2;

    int hash(const std::string& key, int i) const {
        return (hash1(key) + i * hash2(hash1(key))) % size;
    }

public:
    BloomFilter(int s, int nHashes) : size(s), numHashes(nHashes), bitset(s, false) {}

    void add(const std::string& key) {
        for (int i = 0; i < numHashes; ++i) {
            bitset[hash(key, i)] = true;
        }
    }

    bool contains(const std::string& key) const {
        for (int i = 0; i < numHashes; ++i) {
            if (!bitset[hash(key, i)]) {
                return false;  // Definitely not in the set
            }
        }
        return true;  // Might be in the set, but could be a false positive
    }
};

int main() {
    BloomFilter filter(1000, 3);  // Using 1000 bits and 3 hash functions

    filter.add("test");
    filter.add("sample");
    filter.add("example");

    std::cout << "test: " << filter.contains("test") << std::endl;  // Expected: 1 (true)
    std::cout << "sample: " << filter.contains("sample") << std::endl;  // Expected: 1 (true)
    std::cout << "example: " << filter.contains("example") << std::endl;  // Expected: 1 (true)
    std::cout << "hello: " << filter.contains("hello") << std::endl;  // Expected: 0 (false), but could be 1 due to false positives

    return 0;
}
