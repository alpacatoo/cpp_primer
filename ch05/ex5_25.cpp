#include <iostream>
#include <stdexcept>
using namespace std;
int main()
{
    int i, j;
    while(cin >> i >> j)
    {
        try
        {
            if (j == 0)
                throw std::runtime_error("divisor is 0");
            cout << i / j << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (c != 'y')
                break;
        }
        cout << "please input tow numbers: " << endl;
    }

    return 0;
}