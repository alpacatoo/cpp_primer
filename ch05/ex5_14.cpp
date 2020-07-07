#include <iostream>
#include <string>
using namespace std;
int main()
{ 
    string prestring;
    int count = 0;
    string maxString;
    int maxCount = 0;
    for (string s; std::cin >> s; prestring = s)
    {
        if (s == prestring) ++count;
        else count = 0;
        if (count > maxCount)
        {
            maxCount = count;
            maxString = s;
        }
    }
    if (maxString.empty())
        cout << "There's no duplicated string." << endl;
    else
        cout << "the word " << maxString << " occurred " << maxCount + 1 << " times. " << endl;
    return 0;
}