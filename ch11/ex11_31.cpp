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

    auto found = authors.find(author);  //ָ���һ���ؼ���Ϊauthor�ĵ�����
    auto num = authors.count(author);   //���عؼ���Ϊauthor��Ԫ�ظ���

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