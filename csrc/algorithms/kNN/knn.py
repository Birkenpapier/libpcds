import knn_module
import numpy as np

# Example data
X_train = [[0.5, 0.2], [0.9, 0.3], [0.1, 0.8], [0.4, 0.4], [0.7, 0.6]]
y_train = [0, 0, 1, 1, 0]
X_test = [[0.3, 0.3], [0.8, 0.5]]

# Convert lists to a format that C++ can understand (if necessary)
X_train = [np.array(x, dtype=np.float64).tolist() for x in X_train]
X_test = [np.array(x, dtype=np.float64).tolist() for x in X_test]

# Create a KNN instance and fit the data
knn = knn_module.KNN(3)  # Initialize with K=3
knn.fit(X_train, y_train)

# Make predictions
predictions = knn.predict(X_test)

print("Predictions:", predictions)
