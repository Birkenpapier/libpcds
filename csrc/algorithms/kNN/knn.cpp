// c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) pybind_knn.cpp -o knn_module$(python3-config --extension-suffix)

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>

class KNN {
public:
    KNN(int K) : K(K) {}

    void fit(const std::vector<std::vector<double>>& X, const std::vector<int>& y) {
        this->X_train = X;
        this->y_train = y;
    }

    std::vector<int> predict(const std::vector<std::vector<double>>& X) {
        std::vector<int> predictions;
        for (const auto& x : X) {
            predictions.push_back(predictSinglePoint(x));
        }
        return predictions;
    }

private:
    int K;
    std::vector<std::vector<double>> X_train;
    std::vector<int> y_train;

    int predictSinglePoint(const std::vector<double>& x) {
        auto comp = [](const std::pair<double, int>& a, const std::pair<double, int>& b) {
            return a.first > b.first;
        };
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, decltype(comp)> pq(comp);

        for (int i = 0; i < X_train.size(); i++) {
            double distance = euclideanDistance(x, X_train[i]);
            pq.push(std::make_pair(distance, y_train[i]));
            if (pq.size() > K) pq.pop();
        }

        std::vector<int> k_labels(K, 0);
        for (int i = 0; i < K; i++) {
            k_labels[i] = pq.top().second;
            pq.pop();
        }

        return mostCommonLabel(k_labels);
    }

    double euclideanDistance(const std::vector<double>& a, const std::vector<double>& b) {
        double sum = 0;
        for (int i = 0; i < a.size(); i++) {
            sum += (a[i] - b[i]) * (a[i] - b[i]);
        }
        return sqrt(sum);
    }

    int mostCommonLabel(const std::vector<int>& labels) {
        std::unordered_map<int, int> count;
        for (int label : labels) {
            count[label]++;
        }
        int max_count = 0, most_common = -1;
        for (const auto& pair : count) {
            if (pair.second > max_count) {
                max_count = pair.second;
                most_common = pair.first;
            }
        }
        return most_common;
    }
};
