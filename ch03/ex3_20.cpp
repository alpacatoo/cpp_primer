#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (vector<int>::size_type pos = 0; pos < v.size() - 1; ++pos)
        std::cout << v[pos] + v[pos + 1] << std::endl;
    int beginPos = 0;
    int endPos = v.size() - 1;
    while (beginPos <= endPos)
    {
        std::cout << v[beginPos] + v[endPos] << std::endl;
        beginPos++;
        endPos--;
    }
    return 0;
}