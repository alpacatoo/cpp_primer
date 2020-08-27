#include <iostream>
#include <string>
using std::string;

void replace_with(string &s, string oldval, string newval)
{
    size_t curr = 0;
    while (curr < (s.size()-oldval.size()))
    {
        if (oldval == s.substr(curr, oldval.size()))
        {
            s = s.replace(curr,oldval.size(),newval);
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
    replace_with(s, "love", "le");
    std::cout << s << std::endl;
    return EXIT_SUCCESS;
}