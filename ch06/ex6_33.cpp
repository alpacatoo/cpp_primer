#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>::const_iterator first, vector<int>::const_iterator last)
{
    if (first == last)
    {
        cout << "END" << endl;
        return;
    }
    cout << *first << " ";
    print(++first, last);
}
int main()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print(v.cbegin(),v.cend());
    return 0;
}