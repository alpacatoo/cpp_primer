#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool chNum(const string &s)
{
    return s.size() >= 5 ? true : false;
}
int main()
{
    vector<string> v{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto par_end = partition(v.begin(), v.end(), chNum);
    for (auto curr = v.begin(); curr != par_end; ++curr)
        cout << *curr << endl;
    return EXIT_SUCCESS;
}