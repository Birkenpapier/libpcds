#include <iostream>
#include <cassert>

class RingBuffer
{
public:
    RingBuffer();

    void push(int val);
    int pop();
    int get(int offset);
    void clear();
    void increment(int& i) const;
    void decrement(int& i) const;

private:
    const static int I_BUFFER_SIZE = 10;
    
    int buffer[I_BUFFER_SIZE];
    int i_head = 0;
    int i_tail = 0;
    bool b_is_empty = true;
};
