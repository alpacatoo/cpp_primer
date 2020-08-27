#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
int main()
{
    std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    std::sort(vs.begin(), vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    auto iter = std::unique(vs.begin(), vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    vs.erase(iter, vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}