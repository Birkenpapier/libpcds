#include "ringbuffer.hpp"

int main(int argc, const char* argv[])
{
    RingBuffer buf;
    
    buf.push(1);
    buf.push(2);
    buf.push(3);
    buf.push(4);
    
    assert(buf.get(0) == 1);
    assert(buf.get(1) == 2);
    assert(buf.get(2) == 3);
    assert(buf.get(3) == 4);
    
    for (int i = 0; i < 1000; i++)
        buf.push(123);
    
    assert(buf.get(0) == 123);
    assert(buf.get(9) == 123);
    
    buf.clear();
    buf.push(321);
    assert(buf.get(0) == 321);
    
    std::cout << "ring buffer is working correctly" << std::endl;
    
    return 0;
}
