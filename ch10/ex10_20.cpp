#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int bigerthan6(const vector<string> &words)
{
    return count_if(words.begin(), words.end(), [](const string &s)
                                                    {return s.size() > 6; });
}
int main()
{
    vector<string> vs{"dfdf", "kubernetes", "world", "docker", "goodbye"};
    cout << bigerthan6(vs) << endl;
    return EXIT_SUCCESS;
}