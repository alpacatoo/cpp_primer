#include <deque>
#include <string>
#include <iostream>
using std::deque;
using std::string;
int main()
{
    deque<string> inDequeString;
    string inString;
    while (std::cin >> inString)
        inDequeString.push_back(inString);
    for (auto s : inDequeString)
        std::cout << s << std::endl;
    return EXIT_SUCCESS;
}