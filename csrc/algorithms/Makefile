# Makefile for libpdcs algorithms

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Library settings
LIBRARY_NAME = libpdcs_algorithms
LIBRARY_FILE = $(LIBRARY_NAME).a

# Source directories
SRC_DIRS = a_star dijkstra floyd_warshall_algorithm genetic hamming_distance heap_sort kMeans kNN leftpad longest_increasing_subsequence matrix_chain_multiplication naive_bayes_classifier simulated_annealing strassen_matrix_multiplication tanimoto_coefficient

# Source files
SOURCES = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files directory
INCLUDE_DIR = algorithms

# Build the library
$(LIBRARY_FILE): $(OBJECTS)
	ar rcs $@ $^

# Generic rule for building objects
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean the build
clean:
	rm -f $(LIBRARY_FILE) $(OBJECTS)

# Install the library (optional)
install: $(LIBRARY_FILE)
	mkdir -p /usr/local/lib /usr/local/include/$(LIBRARY_NAME)
	cp $(LIBRARY_FILE) /usr/local/lib
	cp -r $(INCLUDE_DIR)/* /usr/local/include/$(LIBRARY_NAME)
