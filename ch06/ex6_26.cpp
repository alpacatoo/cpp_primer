#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    for (int i = 1; i != argc; ++i)
        std::cout << argv[i] << std::endl;
    return 0;
}