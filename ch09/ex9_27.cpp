#include <forward_list>
#include <iostream>
using std::forward_list;
int main()
{
    forward_list<int> fl{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while (curr != fl.end())
    {
        if (*curr & 0x1)
        {
            prev = curr;
            ++curr;
        }
        else
            curr = fl.erase_after(prev);
        
    }
    for (auto i : fl)
        std::cout << i << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}