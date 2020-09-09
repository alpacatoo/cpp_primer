#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    map<string, vector<pair<string,string>>> m;
    string tempString;
    while (getline(cin, tempString))
    {
        istringstream inString(tempString);
        string lastName, firstName, birthday;
        inString >> lastName;
        inString >> firstName;
        inString >> birthday;
        m[lastName].push_back({ firstName, birthday });
    }
    cout << "Output Result:" << endl;
    auto iter = m.begin();
    while (iter != m.end())
    {
        for (auto name : iter->second)
        {
            cout << iter->first << " "
                << name.first << " "
                << name.second << endl;
        }
        ++iter;
    }

    return EXIT_SUCCESS;
}