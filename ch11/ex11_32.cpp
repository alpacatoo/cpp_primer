#include <iostream>
#include <map>
#include <set>
#include <string>
using std::string;
int main()
{
    std::multimap<string, string> authors{
        { "aaa", "bbb" },
        { "ddd", "ddd" },
        { "ccc", "eee" },
        { "ccc", "fff" } };

    std::map<string, std::multiset<string>> order_authors;
    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);
    for (const auto &author : order_authors)
    {
        std::cout << author.first << ": ";
        for (const auto &book : author.second)
            std::cout << book << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}