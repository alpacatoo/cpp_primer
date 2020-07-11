#include <iostream>
#include <vector>
#include <string>
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
void(*f1(string a))(vector<int>::const_iterator first, vector<int>::const_iterator last)
{
    cout << a << endl;
    return print;
}

int main()
{
    vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    void(*p1)(vector<int>::const_iterator first, vector<int>::const_iterator last);
    p1 = f1("hello");
    p1(v.cbegin(), v.cend());
    //print(v.cbegin(), v.cend());
    return 0;
}