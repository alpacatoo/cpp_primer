#include <string>
#include <iostream>
#include <vector>
int sum_int(std::vector<std::string> & v)
{
    int sum = 0;
    for (auto i : v)
        sum += std::stoi(i);
    return sum;
}
double sum_double(std::vector<std::string> &v)
{
    double sum = 0.0;
    for (auto d : v)
    {
        sum += std::stod(d);
    }
    return sum;
}
int main()
{
    std::vector<std::string> v{"1", "2.5", "3.2"};
    std::cout << sum_int(v) << std::endl;
    std::cout << sum_double(v) << std::endl;
    return EXIT_SUCCESS;
}