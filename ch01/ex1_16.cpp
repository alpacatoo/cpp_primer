#include <iostream>

int main()
{
    int sum = 0, value = 0;
    //input Ctrl+z to stop input number
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << sum << std::endl;
    return 0;
}