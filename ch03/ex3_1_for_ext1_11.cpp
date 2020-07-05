#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int count = 10;
    int hi = 0, lo = 0, temp = 0;
    cout << "Input low number:" << endl;
    cin >> lo;
    cout << "Input high number:" << endl;
    cin >> hi;

    while (lo <= hi)
    {
        cout << lo << endl;
        lo++;
    }
}