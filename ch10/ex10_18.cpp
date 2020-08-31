#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
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
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = partition(words.begin(), words.end(),
                            [sz](const std::string &s)
                                {return s.size() < sz; });
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
    biggies_partition(v, 2);
    return EXIT_SUCCESS;
}