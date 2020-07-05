#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v(10,42);
    for (auto &num : v)
    {
        num *= 2;
        std::cout << num << std::endl;
    }
    return 0;
}