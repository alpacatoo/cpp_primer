#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int i = 6;
    auto f = [&i]() -> bool{return i > 0 ? --i : i; };
    while (f())
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}