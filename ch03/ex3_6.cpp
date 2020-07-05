#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    std::cin >> s;
    for (auto &c : s)
        c = 'X';
    std::cout << s << std::endl;
    return 0;
}