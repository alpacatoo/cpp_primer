#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
    {
        v.push_back(i);
    }
    for (auto c : v)
        std::cout << c << std::endl;
    return 0;
}