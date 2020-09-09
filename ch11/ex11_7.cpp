#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    map<string, vector<string>> m;
    string tempString;
    while (getline(cin, tempString))
    {
        istringstream inString(tempString);
        string lastName, firstName;
        inString >> lastName;
        inString >> firstName;
        m[lastName].push_back(firstName);
    }
    cout << "Output Result:" << endl;
    auto iter = m.begin();
    while (iter != m.end())
    {
        for (auto name : iter->second)
        {
            cout << iter->first << " " << name << endl;
        }
        ++iter;
    }

    return EXIT_SUCCESS;
}