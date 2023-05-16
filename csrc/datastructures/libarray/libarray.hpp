#include <stdexcept>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define I_MINIMAL_SIZE 10

template <class T>
class LibArray
{
    public:
        LibArray();

        void push(T t_element);
        T pop();
        void set(size_t l_index, T t_element);
        T get(size_t l_index);
        size_t size();
        size_t capacity();
        void print();
        int is_empty();
        
        ~LibArray();
    private:
        size_t l_size;
        size_t l_range;
        T* pl_data;
        void resize(size_t l_factor);
};
