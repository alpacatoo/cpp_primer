#include <iostream>
#include <string>
using std::string;

void replace_with(string &s, string oldval, string newval)
{
    auto curr = s.begin();
    while (curr != (s.end()-oldval.size()))
    {
        if (oldval == string(curr, curr+oldval.size()))
        {
            curr = s.erase(curr, curr + oldval.size());
            curr = s.insert(curr, newval.begin(), newval.end());
            curr += newval.size();
        }
        else
            ++curr;
    }
}

int main()
{
    string s{ "hello how thru world thu like love haha tho end." };
    std::cout << s << std::endl;
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    std::cout << s << std::endl;
    return EXIT_SUCCESS;
}