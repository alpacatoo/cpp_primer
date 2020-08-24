#include <forward_list>
#include <string>
#include <iostream>
using std::forward_list;
using std::string;
forward_list<string>::iterator myInsert(forward_list<string> &list, string s, string i)
{
    auto prev = list.before_begin();
    auto curr = list.begin();
    while (curr != list.end())
    {
        if (*curr == s)
            return list.insert_after(curr, i);
        prev = curr;
        ++curr;
    }
    return list.insert_after(prev, i);
}
void myPrint(forward_list<string>  &list)
{
    for (auto &s:list)
        std::cout << s << ",";
    std::cout << std::endl;
}
int main()
{
    forward_list<string> list1{"hello", "like", "OK"};
    forward_list<string> list2 = list1;
    string search = "like";
    string in = "world";
    myInsert(list1, search, in);
    myPrint(list1);
    search = "bye";
    myInsert(list2, search, in);
    myPrint(list2);
    return EXIT_SUCCESS;
}