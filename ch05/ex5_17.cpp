#include <iostream>
#include <vector>
using namespace std;
bool is_prefix(const vector<int> &s, const vector<int>&l)
{
    if (s.size() > l.size())
    {
        return is_prefix(l, s);
    }
    for (int i = 0; i != s.size(); ++i)
    {
        if (s[i] != l[i])
            return false;
    }
    return true;
}
int main()
{
    vector<int> a{1, 1, 3, 2, 5};
    vector<int> b{ 1, 1, 3, 2, 5, 7, 7 };
    cout << (is_prefix(b, a) ? "Yes" : "No") << endl;
    return 0;
}