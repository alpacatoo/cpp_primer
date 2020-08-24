#include <vector>
#include <iostream>
using std::vector;
vector<int>::const_iterator find(vector<int>::const_iterator begin,
    vector<int>::const_iterator end,
    int ref)
{
    while (begin != end)
    {
        if (*begin == ref)
            return begin;
        ++begin;
    }
    return end;
}

int main()
{
    int inputInt;
    vector<int> nums{ 3, 4, 1, 6, 5 };
    while (std::cin >> inputInt)
    {
        if (find(nums.cbegin(), nums.cend(), inputInt) == nums.cend())
            std::cout << "There are no this number." << std::endl;
        else
            std::cout << "Find number: " << inputInt << std::endl;
    }

    return EXIT_SUCCESS;
}