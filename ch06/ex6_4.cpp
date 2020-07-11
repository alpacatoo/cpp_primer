#include <iostream>
using namespace std;
int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}
void interactive_fact()
{
    unsigned int number;
    cout << "Please Input a inter number or eof:";
    while (cin >> number)
    {
        cout << "the result is " << fact(number) << endl;
        cout << "Please Input a inter number or eof:";
    }
}
int main()
{
    interactive_fact();
    return 0;
}