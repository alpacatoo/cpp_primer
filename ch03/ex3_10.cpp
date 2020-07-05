#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
int main()
{
    string s = "I'm don't sleep! go ahead.";
    string result;
    for (auto c : s)
        if (!ispunct(c))
            result += c;
    cout << result << endl;
    return 0;
}