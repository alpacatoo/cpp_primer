#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> vs = { "aaa", "bbb" };
    string inString;
    while (cin >> inString)
    {
        if (vs.cend() == find(vs.cbegin(), vs.cend(), inString))
        {
            vs.push_back(inString);
        }
    }

    cout << "Output:" << endl;
    for (auto &s : vs)
    {
        cout << s << endl;
    }
    return EXIT_SUCCESS;
}