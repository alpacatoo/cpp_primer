#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int check_size(const string &s, const int i)
{
    return i > static_cast<int>(s.size());
}
int main()
{
    vector<int> vi{ 1, 2, 3, 4, 5, 6, 7 };
    string s = "like";
    auto wc = find_if(vi.cbegin(), vi.cend(), bind(check_size, s, _1));
    cout << *wc << endl;
    return EXIT_SUCCESS;
}