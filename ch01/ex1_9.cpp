#include <iostream>

int main()
{
    int sum = 0, count = 50;
    while (count <= 100)
    {
        sum += count;
        count++;
    }
    std::cout << sum << std::endl;
}