#include "ringbuffer.hpp"

RingBuffer::RingBuffer() {}

void RingBuffer::push(int val) {
    buffer[i_tail] = val;
    increment(i_tail);
    b_is_empty = false;
}

int RingBuffer::pop() {
    assert(i_tail - i_head > 0);
    
    int val = buffer[i_tail];
    decrement(i_tail);
    
    if (i_tail == i_head)
        b_is_empty = true;
    
    return val;
}

int RingBuffer::get(int offset) {
    assert(offset < I_BUFFER_SIZE);
    assert(i_head != i_tail);
    
    if (i_head + offset > I_BUFFER_SIZE)
        return buffer[i_head + offset - I_BUFFER_SIZE];
    
    return buffer[i_head + offset];
}

void RingBuffer::clear() {
    i_head = 0;
    i_tail = 0;
}

void RingBuffer::increment(int& i) const {
    i = (i + 1 < I_BUFFER_SIZE) ? (i + 1) : (0);
}

void RingBuffer::decrement(int& i) const {
    i = (i - 1 >= 0) ? (i - 1) : (I_BUFFER_SIZE - 1);
}
