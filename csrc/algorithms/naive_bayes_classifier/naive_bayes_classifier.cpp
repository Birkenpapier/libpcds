#include <iostream>
#include <map>
#include <vector>
#include <string>

// calculate the probabilities of each class
std::map<std::string, double> calculateClassProbabilities(const std::map<std::string, int>& classCounts, int totalSamples) {
    std::map<std::string, double> classProbabilities;
    for (const auto& pair : classCounts) {
        classProbabilities[pair.first] = static_cast<double>(pair.second) / totalSamples;
    }
    return classProbabilities;
}

// calculate conditional probabilities
double calculateConditionalProbability(int count, int total, int numClasses) {
    return static_cast<double>(count + 1) / (total + numClasses);
}

// main class
class NaiveBayesClassifier {
    std::map<std::string, int> classCounts;
    std::map<std::string, std::map<std::string, std::map<std::string, int>>> featureCounts;
    std::map<std::string, int> featureTotals;
    int totalSamples = 0;
    int numFeatures;
    int numClasses;

public:
    NaiveBayesClassifier(int numFeatures, int numClasses) : numFeatures(numFeatures), numClasses(numClasses) {}

    // train
    void train(const std::vector<std::vector<std::string>>& data) {
        for (const auto& row : data) {
            std::string classValue = row.back();
            classCounts[classValue]++;
            totalSamples++;

            for (int i = 0; i < numFeatures; i++) {
                featureCounts[classValue][std::to_string(i)][row[i]]++;
                featureTotals[std::to_string(i)]++;
            }
        }
    }

    // predict
    std::string predict(const std::vector<std::string>& sample) {
        std::map<std::string, double> classProbabilities = calculateClassProbabilities(classCounts, totalSamples);
        std::string bestClass;
        double bestProb = -1;

        for (const auto& classProb : classProbabilities) {
            std::string className = classProb.first;
            double prob = classProb.second;

            for (int i = 0; i < numFeatures; i++) {
                prob *= calculateConditionalProbability(featureCounts[className][std::to_string(i)][sample[i]], featureTotals[std::to_string(i)], numClasses);
            }

            if (prob > bestProb) {
                bestProb = prob;
                bestClass = className;
            }
        }

        return bestClass;
    }
};

int main() {
    // sample data
    std::vector<std::vector<std::string>> data = {
        {"sunny", "hot", "high", "false", "no"},
        {"sunny", "hot", "high", "true", "no"},
        // extend if wished
    };

    int numFeatures = 4; // n of features (excluding class label)
    int numClasses = 2;  // n of class labels

    NaiveBayesClassifier classifier(numFeatures, numClasses);
    classifier.train(data);

    // prediction
    std::vector<std::string> newSample = {"sunny", "cool", "high", "true"};
    std::string predictedClass = classifier.predict(newSample);
    std::cout << "predicted Class: " << predictedClass << std::endl;

    return 0;
}
