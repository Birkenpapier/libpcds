#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class SuffixArray {
private:
    std::string text;
    std::vector<int> suffixArr;

    static bool suffixCompare(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        return a.second < b.second;
    }

public:
    SuffixArray(const std::string& txt) : text(txt) {
        buildSuffixArray();
    }

    void buildSuffixArray() {
        std::vector<std::pair<int, std::string>> suffixes;
        for (int i = 0; i < text.length(); ++i) {
            suffixes.push_back({i, text.substr(i)});
        }

        std::sort(suffixes.begin(), suffixes.end(), suffixCompare);

        suffixArr.clear();
        for (const auto& suf : suffixes) {
            suffixArr.push_back(suf.first);
        }
    }

    void printSuffixArray() {
        for (int i : suffixArr) {
            std::cout << i << ": " << text.substr(i) << std::endl;
        }
    }

    bool search(const std::string& pattern) {
        int l = 0, r = suffixArr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = text.compare(suffixArr[mid], pattern.length(), pattern);

            if (res == 0) {
                return true;
            }
            if (res < 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};

int main() {
    std::string txt = "banana";
    SuffixArray sa(txt);

    std::cout << "Suffix Array for the string \"" << txt << "\":" << std::endl;
    sa.printSuffixArray();

    std::string pattern = "nan";
    std::cout << "Searching for \"" << pattern << "\": "
              << (sa.search(pattern) ? "Pattern Found" : "Pattern Not Found") << std::endl;

    return 0;
}
