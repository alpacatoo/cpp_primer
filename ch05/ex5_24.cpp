#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int i, j;
    cin >> i >> j;
    if (j == 0)
        throw std::runtime_error("divisor is 0");
    cout << i / j << endl;

    return 0;
}