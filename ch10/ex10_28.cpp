#include <vector>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
int main()
{
    vector<int> vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> l_back, l_front, l_insert;
    copy(vi.cbegin(), vi.cend(), back_inserter(l_back));
    copy(vi.cbegin(), vi.cend(), front_inserter(l_front));
    copy(vi.cbegin(), vi.cend(), inserter(l_insert,l_insert.begin()));
    for (auto i : l_back)
        cout << i << " ";
    cout << endl;
    for (auto i : l_front)
        cout << i << " ";
    cout << endl;
    for (auto i : l_insert)
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}