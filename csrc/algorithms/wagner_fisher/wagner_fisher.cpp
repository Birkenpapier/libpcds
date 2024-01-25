#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> load_dictionary(const std::string &file_path) {
    std::vector<std::string> dictionary;
    std::string line;
    std::ifstream file(file_path);

    if (file.is_open()) {
        while (std::getline(file, line)) {
            dictionary.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return dictionary;
}

int wagner_fischer(const std::string &s1, const std::string &s2) {
    int len_s1 = s1.size();
    int len_s2 = s2.size();
    std::vector<int> current_row(len_s1 + 1);

    for (int i = 0; i <= len_s1; ++i) {
        current_row[i] = i;
    }

    for (int i = 1; i <= len_s2; ++i) {
        auto previous_row = current_row;
        current_row[0] = i;
        for (int j = 1; j <= len_s1; ++j) {
            int add = previous_row[j] + 1;
            int del = current_row[j - 1] + 1;
            int change = previous_row[j - 1];
            if (s1[j - 1] != s2[i - 1]) {
                change += 1;
            }
            current_row[j] = std::min({add, del, change});
        }
    }

    return current_row[len_s1];
}

std::vector<std::pair<std::string, int>> spell_check(const std::string &word, const std::vector<std::string> &dictionary) {
    std::vector<std::pair<std::string, int>> suggestions;

    for (const auto &correct_word : dictionary) {
        int distance = wagner_fischer(word, correct_word);
        suggestions.emplace_back(correct_word, distance);
    }

    std::sort(suggestions.begin(), suggestions.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    if (suggestions.size() > 10) {
        suggestions.resize(10);
    }

    return suggestions;
}

int main() {
    auto dictionary = load_dictionary("words.txt");
    std::string misspelled_word = "wrlod";
    auto suggestions = spell_check(misspelled_word, dictionary);

    std::cout << "Top 10 suggestions for '" << misspelled_word << "':" << std::endl;
    for (const auto &pair : suggestions) {
        std::cout << pair.first << " (Distance: " << pair.second << ")" << std::endl;
    }

    return 0;
}
