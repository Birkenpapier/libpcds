#include "segment_tree.hpp"

int main() {
    std::vector<int> values = {1, 3, 5, 7, 9, 11};
    SegmentTree st(values);
    
    int sum = st.rangeSum(1, 3);
    std::cout << "Sum from index 1 to 3: " << sum << std::endl;

    st.updateValue(1, 10);
    
    sum = st.rangeSum(1, 3);
    std::cout << "Sum from index 1 to 3 after update: " << sum << std::endl;

    return 0;
}
