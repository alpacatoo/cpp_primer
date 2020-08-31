#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void elimDups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());
    auto v_uniq = unique(vs.begin(), vs.end());
    vs.erase(v_uniq, vs.end());
}
string make_plural(const int size, const string &s, const string &ending)
{
    return size > 1 ? s + ending : s;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
            { return a.size() < b.size(); });
    cout << "stable_sort result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> v{ "a", "aaaaaabba", "bbb", "aa", "bba", "aa", "a", "aaaaaabba", "aaa", "bbb" };
    biggies(v, 2);
    return EXIT_SUCCESS;
}