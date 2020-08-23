#include <iostream>
#include <sstream>
#include <string>
std::istream& func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istringstream ss("hello world!!");
    func(ss);
    return 0;
}