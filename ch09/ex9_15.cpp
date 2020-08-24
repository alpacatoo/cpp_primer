#include <vector>
#include <iostream>
using std::vector;
int main()
{
    vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> v2 = { 1, 2, 3, 4 };
    std::cout << (v1 == v2 ? "True" : "False") << std::endl;
    std::cout << (v1 > v2 ? "True" : "False") << std::endl;
    return EXIT_SUCCESS;
}