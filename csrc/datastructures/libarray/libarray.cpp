#include "libarray.hpp"

template <class T>
LibArray<T>::LibArray() {
    l_range = I_MINIMAL_SIZE;
    l_size = 0;
    pl_data = (T*)malloc(l_range * sizeof(*pl_data));
    if (!pl_data)
        throw std::bad_alloc();
}

template <class T>
void LibArray<T>::push(T t_element) {
    if (l_size >= l_range)
        resize(2);
    *(pl_data + l_size++) = t_element;
}

template <class T>
T LibArray<T>::pop() {
    return *(pl_data + --l_size);
}

template <class T>
void LibArray<T>::set(size_t l_index, T t_element) {
    while (l_index >= l_size)
        this->push(0);
    *(pl_data + l_index) = t_element;
}


template <class T>
T LibArray<T>::get(size_t l_index) {
    return *(pl_data + l_index);
}

template <class T>
size_t LibArray<T>::size() {
    return l_size;
}

template <class T>
size_t LibArray<T>::capacity() {
    return l_range;
}


template <class T>
void LibArray<T>::print() {
    size_t i = 0;
    while (i < l_size) {
        std::cout << "[PRINTOP] -> [" << i << "] = " << this->get(i) << "\n";
        i++;
    }
}

template <class T>
int LibArray<T>::is_empty() {
    return l_size == 0;
}

template <class T>
LibArray<T>::~LibArray() {
    free(pl_data);
}

template <class T>
void LibArray<T>::resize(size_t l_factor) {
    size_t l_local_range = l_range * l_factor;
    T *t_tmp = (T*)realloc(pl_data, l_local_range * sizeof(*pl_data));
    if (!t_tmp)
        throw std::bad_alloc();
    pl_data = t_tmp;
    l_range = l_local_range;
}

template class LibArray<int>;
template class LibArray<long>;
template class LibArray<float>;
template class LibArray<size_t>;
template class LibArray<std::string>;
