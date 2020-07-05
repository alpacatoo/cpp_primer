#include <iostream>

int main()
{
    int count = 10;
    int hi = 0, lo = 0, temp = 0;
    std::cout << "Input low number:" << std::endl;
    std::cin >> lo;
    std::cout << "Input high number:" << std::endl;
    std::cin >> hi;

    while (lo <= hi)
    {
        std::cout << lo << std::endl;
        lo++;
    }
}