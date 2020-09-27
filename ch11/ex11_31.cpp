#include <iostream>
#include <map>
#include <string>
using std::string;
using std::multimap;
int main()
{
    std::multimap<string, string> authors{
        { "aaa", "bbb" },
        { "ddd", "ddd" },
        { "ccc", "eee" },
        { "ccc", "fff" } };

    string author = "ccc";
    string book = "fff";

    auto found = authors.find(author);  //指向第一个关键字为author的迭代器
    auto num = authors.count(author);   //返回关键字为author的元素个数

    while (num)
    {
        if (found->second == book)
        {
            authors.erase(found);
            break;
        }
        ++found;
        --num;
    }

    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;

    return EXIT_SUCCESS;
}