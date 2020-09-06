#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
int main()
{
    //vector<int> vi{ 1, 1, 2, 3, 4, 3, 2, 4, 6, 5, 6, 7, 5 };
    vector<int> vi{ 1, 1, 2, 2, 2, 4, 4, 4, 3, 3, 3 };
    list<int> li;
    //unique只能去除相临重复元素
    unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));
    for (auto i : li)
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}