#include <iostream>
#include "./fenwick_tree.cpp"

int main() {
    std::vector<int> values = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(values);

    // Find sum from index 0 to 3. Result should be 1 + 3 + 5 + 7 = 16
    int sum = ft.rangeSum(0, 3);
    std::cout << "Sum from index 0 to 3: " << sum << std::endl;

    // Update value at index 1, adding 7 to the existing value
    ft.update(1, 7);
    
    // Now, find sum from index 0 to 3. Result should be 1 + 10 + 5 + 7 = 23
    sum = ft.rangeSum(0, 3);
    std::cout << "Sum from index 0 to 3 after update: " << sum << std::endl;

    return 0;
}
