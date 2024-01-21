#include <iostream>
#include <vector>
#include <algorithm>

// util function to print the LIS
void printLIS(const std::vector<int>& a, const std::vector<int>& p, int i) {
    if (p[i] == -1) {
        std::cout << a[i] << " ";
        return;
    }
    printLIS(a, p, p[i]);
    std::cout << a[i] << " ";
}

int longestIncreasingSubsequence(const std::vector<int>& a) {
    int n = a.size();
    std::vector<int> dp(n, 1), predecessor(n, -1);

    int maxLength = 0, bestEnd = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                predecessor[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            bestEnd = i;
        }
    }

    std::cout << "Longest Increasing Subsequence: ";
    printLIS(a, predecessor, bestEnd);
    std::cout << "\n";

    return maxLength;
}

int main() {
    std::vector<int> sequence = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int length = longestIncreasingSubsequence(sequence);
    std::cout << "Length of LIS is " << length << std::endl;
    return 0;
}
