#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (auto it = v.begin(); it != v.end() - 1; it++)
        std::cout << *it + *(it + 1) << std::endl;
    auto beginIt = v.begin();
    auto endIt = v.end() - 1;
    while (beginIt <= endIt)
    {
        std::cout << *beginIt + *endIt << std::endl;
        beginIt++;
        endIt--;
    }
    return 0;
}