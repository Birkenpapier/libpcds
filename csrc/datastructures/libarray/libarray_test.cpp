#include "libarray.hpp"

int main()
{
    LibArray<int> libarr;

    for (int i = 0; i < 50; i++)
        libarr.push(20 - i);

    libarr.print();

    std::cout << "[INFOP] pop(): " << libarr.pop() << "\n";

    libarr.push(987);
    libarr.set(2, 98765);
    libarr.print();

    return 0;
}
