#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    while (getline(std::cin, s))
    {
        std::cout << s << std::endl;
    }
    return 0;
}