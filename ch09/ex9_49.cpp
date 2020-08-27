#include <string>
#include <iostream>
#include <fstream>
using std::string;
int main()
{
    std::ifstream ifs("../ch09/find.txt");
    if (!ifs)   return EXIT_FAILURE;
    string s,longest;
    while (ifs >> s)
    {
        if (string::npos == s.find_first_not_of("aceimnorsuvwxz"))
        {
            longest = longest.size() < s.size() ? s : longest;
        }
    }
    std::cout << longest << std::endl;
    return EXIT_SUCCESS;
}