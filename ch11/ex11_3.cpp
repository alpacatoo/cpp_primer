#include <iostream>
#include <map>
#include <string>
using namespace std;
void word_count(map<string, int> m)
{
    string s;
    while (cin >> s){
        m[s] += 1;
    }
    for (const auto& elem : m)
        std::cout << elem.first << " : " << elem.second << endl;
}
int main()
{
    map<string, int> m;
    word_count(m);
    return EXIT_SUCCESS;
}