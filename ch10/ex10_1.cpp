#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> v{ 2, 1, 5, 3, 7, 4, 2, 4, 6, 2 };
    std::cout << std::count(v.cbegin(), v.cend(), 2) << std::endl;
    return EXIT_SUCCESS;
}