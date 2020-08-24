#include <vector>
#include <iostream>
#include <list>
using std::list;
using std::vector;
int main()
{
    list<int> v1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> v2 = { 1, 2, 3, 4 };
    std::cout << (vector<int>(v1.begin(),v1.end()) == v2 ? "True" : "False") << std::endl;
    std::cout << (vector<int>(v1.begin(), v1.end()) > v2 ? "True" : "False") << std::endl;
    return EXIT_SUCCESS;
}