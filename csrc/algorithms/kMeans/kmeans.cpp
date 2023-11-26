// build c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3 -m pybind11 --includes) pybind_kmeans.cpp -o kmeans_module$(python3-config --extension-suffix)
#include <vector>
#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

class KMeans {
public:
    KMeans(int K, int max_iters) : K(K), max_iters(max_iters) {}

    void fit(const std::vector<std::vector<double>>& data) {
        int n = data.size();
        int m = data[0].size();
        std::vector<std::vector<double>> centroids(K, std::vector<double>(m, 0));
        std::vector<int> labels(n, 0);

        // Initialize centroids randomly
        for (auto& centroid : centroids) {
            for (auto& val : centroid) {
                val = ((double) rand() / RAND_MAX);
            }
        }

        for (int iter = 0; iter < max_iters; ++iter) {
            // Assignment step
            for (int i = 0; i < n; ++i) {
                double min_dist = std::numeric_limits<double>::max();
                for (int j = 0; j < K; ++j) {
                    double dist = 0;
                    for (int k = 0; k < m; ++k) {
                        dist += std::pow(data[i][k] - centroids[j][k], 2);
                    }
                    if (dist < min_dist) {
                        min_dist = dist;
                        labels[i] = j;
                    }
                }
            }

            // Update step
            std::vector<int> counts(K, 0);
            for (auto& centroid : centroids) {
                std::fill(centroid.begin(), centroid.end(), 0.0);
            }

            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    centroids[labels[i]][j] += data[i][j];
                }
                counts[labels[i]]++;
            }

            for (int j = 0; j < K; ++j) {
                for (int k = 0; k < m; ++k) {
                    centroids[j][k] /= counts[j];
                }
            }
        }

        this->centroids = centroids;
        this->labels = labels;
    }

    const std::vector<std::vector<double>>& getCentroids() const { return centroids; }
    const std::vector<int>& getLabels() const { return labels; }

private:
    int K, max_iters;
    std::vector<std::vector<double>> centroids;
    std::vector<int> labels;
};
