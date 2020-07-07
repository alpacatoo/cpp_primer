#include <iostream>
#include <string>
using namespace std;
int main()
{
    string read, temp;
    while (cin >> read)
    {
        if (isupper(read[0]) && read == temp) break;
        else temp = read;
    }
    if (cin.eof())cout << "no word was repeated." << endl;
    else cout << read << " occurs twice in succession." << endl;
    return 0;
}