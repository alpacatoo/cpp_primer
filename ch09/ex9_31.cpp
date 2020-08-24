#include <vector>
#include <list>
#include <forward_list>
#include <iostream>
int main()
{
    std::vector<int> vi = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter & 0x1)
        {
            iter = vi.insert(iter, *iter);
            iter += 2;  //复合赋值语句只能用于string、vector、deque、array
        }
        else
        {
            iter = vi.erase(iter);
        }
    }
    for (auto i : vi)
        std::cout << i << ", ";
    std::cout << std::endl;

    std::list<int> list = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter_list = list.begin();
    while (iter_list != list.end())
    {
        if (*iter_list & 0x1)
        {
            iter_list = list.insert(iter_list, *iter_list);
            ++iter_list;
            ++iter_list;
        }
        else
        {
            iter_list = list.erase(iter_list);
        }
    }
    for (auto i : list)
        std::cout << i << ", ";
    std::cout << std::endl;

    std::forward_list<int> forwardlist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = forwardlist.before_begin();
    auto curr = forwardlist.begin();
    while (curr != forwardlist.end())
    {
        if (*curr & 0x1)
        {
            curr = forwardlist.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        }
        else
            curr = forwardlist.erase_after(prev);
    }
    for (auto i : forwardlist)
        std::cout << i << ", ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}