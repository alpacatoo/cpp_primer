#include <iostream>
#include <string>
using std::string;
int main()
{
    string numbers("0123456789");
    string s("ab2c3d7R4E6");
    std::cout << "find_first_of:" << std::endl;
    for (int pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
        std::cout << s[pos] << ", ";
    std::cout << std::endl;
    std::cout << "find_first_not_of:" << std::endl;
    for (int pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos)
        std::cout << s[pos] << ", ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}