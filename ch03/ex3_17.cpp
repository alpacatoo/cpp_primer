#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
int main()
{
    vector<string> origin;
    string s;
    while (std::cin >> s)
        origin.push_back(s);
    for (auto &s : origin)
        for (auto &c : s)
            c = toupper(c);

    for (auto s:origin)
        std::cout << s << std::endl;

    return 0;
}