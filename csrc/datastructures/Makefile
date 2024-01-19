# Makefile for libpdcs

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Library settings
LIBRARY_NAME = libpdcs
LIBRARY_FILE = $(LIBRARY_NAME).a

# Source directories
# SRC_DIRS = bloomfilter fenwick_tree hashtable k_d_tree_2d queue ringbuffer segment_tree stack trie
SRC_DIRS = bloomfilter fenwick_tree hashtable k_d_tree_2d queue ringbuffer stack trie

# Source files
SOURCES = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files directory
INCLUDE_DIR = datastructures

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
