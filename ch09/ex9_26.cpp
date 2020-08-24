#include <vector>
#include <list>
#include <iostream>
using std::vector;
using std::list;
int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> v(std::begin(ia), std::end(ia));
    list<int> l(v.begin(), v.end());

    auto v_iter = v.begin();
    while (v_iter != v.end())
    {
        if (*v_iter & 0x1)
            ++v_iter;
        else
            v_iter = v.erase(v_iter);
    }
    auto l_iter = l.begin();
    while (l_iter != l.end())
    {
        if (*l_iter & 0x1)
            l_iter = l.erase(l_iter);
        else
            ++l_iter;
    }

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : l)
        std::cout << i << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}