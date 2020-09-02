#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool isLessEqthan6(const string &words, string::size_type sz)
{
    return words.size() <= sz;
}
int main()
{
    vector<string> vs{ "dfdf", "kubernetes", "world", "docker", "goodbye" };
    cout << count_if(vs.cbegin(), vs.cend(), bind(isLessEqthan6, _1, 6)) << endl;
    return EXIT_SUCCESS;
}