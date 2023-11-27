#include <vector>
#include <stdexcept>

class TanimotoCoefficientCalculator {
public:
    double compute(const std::vector<bool>& a, const std::vector<bool>& b) {
        if (a.size() != b.size()) {
            throw std::invalid_argument("Vectors must be of equal length");
        }

        int intersection = 0;
        int unionCount = 0;

        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] && b[i]) {
                intersection++;
            }
            if (a[i] || b[i]) {
                unionCount++;
            }
        }

        if (unionCount == 0) return 1.0;  // Both vectors are empty

        return static_cast<double>(intersection) / unionCount;
    }
};
