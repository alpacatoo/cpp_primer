#include <iostream>
#include <string>
#include <map>
using std::string;
int main(void)
{
    std::multimap<string, string> names;
    for (string first, last; std::cin >> first >> last; names.emplace(last, first));
    for (auto const& family : names)
        std::cout << family.second << " " << family.first << std::endl;
    return EXIT_SUCCESS;
}