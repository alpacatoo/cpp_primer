#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
int main()
{
    vector<string> v;
    string s;
    while (std::cin >> s)
    {
        v.push_back(s);
    }
    for (auto s : v)
        std::cout << s << std::endl;
    return 0;
}