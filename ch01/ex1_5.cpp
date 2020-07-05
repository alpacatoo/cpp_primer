#include <iostream>

int main ()
{
    std::cout << "Input two number:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The Product is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}