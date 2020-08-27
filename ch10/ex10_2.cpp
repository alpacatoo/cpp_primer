#include <iostream>
#include <algorithm>
#include <list>
#include <string>
int main()
{
    std::list<std::string> list{ "aaa", "aa", "cc", "bb", "aaa", "ee", "aaa" };
    std::cout << std::count(list.cbegin(), list.cend(), "aaa") << std::endl;
    return EXIT_SUCCESS;
}