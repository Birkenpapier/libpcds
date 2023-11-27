# libpcds - Python Cool Data Structures

libpcds (library For Python With Cool Data Structures And Algorithms) is a versatile C++ template library designed for fast and efficient implementation of various data structures and algorithms, readily usable in Python.

## Warning
> :warning: This software is currently under development and is not yet complete. Users should manage their expectations and use it for experimental or learning purposes only.

> [!WARNING]
> This software is unfinished. Keep your expectations low.

## About libpcds
libpcds is a multipurpose library containing a diverse array of algorithms and data structures aimed at extending Python's capabilities. The library includes:

- **Reimplementations for Fun**: Some classic algorithms and data structures are re-implemented in C++ as an academic exercise, offering insights into their inner workings.
- **New Innovations**: The library also introduces new algorithms and data structures, some of which are unique explorations by the author.

## Building and Installation

### Prerequisites
- C++ Compiler (e.g., g++)
- Python (Version 3.x)
- pybind11

### Building the Library
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Birkenpapier/libpcds.git
   cd libpcds
   ```

2. **Compile the C++ Code**:
   Replace `your_code_file.cpp` with the actual C++ source file name.
   ```bash
   c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` your_code_file.cpp -o your_output_module`python3-config --extension-suffix`
   ```

3. **Using the Library in Python**:
   After compilation, you can import and use the module in your Python scripts.
   ```python
   import your_output_module
   ```

## Examples and Usage
- Further documentation and usage examples will be provided as the library develops.

## Contributions
Contributions to libpcds are welcome! Whether it's adding new features, improving existing ones, or reporting bugs, your input is valuable. Please feel free to open issues or pull requests on the repository.

---