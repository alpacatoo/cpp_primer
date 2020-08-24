#include <iostream>
#include <vector>
using std::vector;
bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int ref)
{
    while (begin != end)
    {
        if (*begin == ref)
        {
            return true;
        }
        ++begin;
    }
    return false;
}

int main()
{
    int inputInt;
    vector<int> nums{3,4,1,6,5};
    while (std::cin >> inputInt)
    {
        std::cout << (find(nums.cbegin(), nums.cend(), inputInt) ? "True" : "False")
            << std::endl;
    }
        
    return EXIT_SUCCESS;
}