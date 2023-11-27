// c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) pybind_hamming_distance.cpp -o hamming_distance_module$(python3-config --extension-suffix)
#include <string>

class HammingDistanceCalculator {
public:
    int compute(const std::string &a, const std::string &b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Strings must be of equal length");
        }

        int distance = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++distance;
            }
        }
        return distance;
    }
};
