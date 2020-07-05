#include <iostream>

int main()
{
    int count = 10;
    std::cout << "Input two number:" << std::endl;
    int hi = 0, lo = 0, temp = 0;
    std::cin >> lo >> hi;

    if (lo > hi)
    {
        temp = hi;
        hi = lo;
        lo = temp;
    }

    while (lo <= hi)
    {
        std::cout << lo << std::endl;
        lo++;
    }
}