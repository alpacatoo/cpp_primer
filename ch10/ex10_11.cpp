#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
int main()
{
    vector<string> v{ "1234", "272", "1111", "1234", "783", "222" };
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter);
    for (auto s: v)
        cout << s << endl;
    return EXIT_SUCCESS;
}