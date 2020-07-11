#include <iostream>
using namespace std;

int larger_one(int i, const int *p)
{
    return (i > *p) ? i : *p;
}

int main()
{
    int i = 6;
    cout << larger_one(7, &i) << endl;

    return 0;
}