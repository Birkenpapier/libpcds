#include "./segment_tree.cpp"

int main() {
    std::vector<int> values = {1, 3, 5, 7, 9, 11};
    SegmentTree st(values);
    
    // Find sum from index 1 to 3. Result should be 3 + 5 + 7 = 15
    int sum = st.rangeSum(1, 3);
    std::cout << "Sum from index 1 to 3: " << sum << std::endl;

    // Update value at index 1 to 10
    st.updateValue(1, 10);
    
    // Now, find sum from index 1 to 3. Result should be 10 + 5 + 7 = 22
    sum = st.rangeSum(1, 3);
    std::cout << "Sum from index 1 to 3 after update: " << sum << std::endl;

    return 0;
}
