#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &i : v)
    {
        i = i & 0x1 ? i * 2 : i;
    }
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}