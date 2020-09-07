#include <iostream>
#include <string>
#include <list>
using namespace std;
void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}
int main()
{
    list<string> l = { "aa", "aad", "aa", "aa", "aasss", "aa" };
    elimDups(l);
    for (const auto& e : l)
        std::cout << e << std::endl;
    return EXIT_SUCCESS;
}