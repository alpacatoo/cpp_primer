#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    std::cin >> s;
    for (char c : s)
        c = 'X';
    std::cout << s << std::endl;
    return 0;
}