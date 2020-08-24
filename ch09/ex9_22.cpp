#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int>  iv{ 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int some_val = 3;
    vector<int>::iterator iter = iv.begin();
    int mid = iv.size() / 2;
    while ((iter - iv.begin()) < mid)
    {
        if (*iter == some_val)
        {
            iter = iv.insert(iter, 2 * some_val);
            ++mid;
            ++iter;
        }
        ++iter;
    }
    for (auto i : iv)
        std::cout << i << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}