#ifndef NAIVE_BAYES_CLASSIFIER_H
#define NAIVE_BAYES_CLASSIFIER_H

#include <iostream>
#include <map>
#include <vector>
#include <string>


/**
 * @class NaiveBayesClassifier
 * @brief A simple Naive Bayes classifier for categorical data.
 *
 * This class implements a basic version of the Naive Bayes algorithm.
 * It assumes all features are categorical and uses Laplace smoothing.
 */
class NaiveBayesClassifier {
    std::map<std::string, int> classCounts;
    std::map<std::string, std::map<std::string, std::map<std::string, int>>> featureCounts;
    std::map<std::string, int> featureTotals;
    int totalSamples = 0;
    int numFeatures;
    int numClasses;

public:
    /**
     * @brief Constructor for the NaiveBayesClassifier class.
     * @param numFeatures Number of features in the dataset.
     * @param numClasses Number of class labels in the dataset.
     */
    NaiveBayesClassifier(int numFeatures, int numClasses);

    /**
     * @brief Trains the classifier with the provided dataset.
     * @param data The training dataset (features + class labels).
     */
    void train(const std::vector<std::vector<std::string>>& data);

    /**
     * @brief Predicts the class label for a given sample.
     * @param sample A vector representing a sample (without class label).
     * @return The predicted class label as a string.
     */
    std::string predict(const std::vector<std::string>& sample);
};

#endif // NAIVE_BAYES_CLASSIFIER_H
