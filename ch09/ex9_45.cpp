#include <iostream>
#include <string>
using std::string;
void add_pre_suffix(string &name, string pre, string suffix)
{
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(suffix);
}
int main()
{
    string name("alpacatoo");
    add_pre_suffix(name, "Mr.", " Jr.");
    std::cout << name << std::endl;
    return EXIT_SUCCESS;
}