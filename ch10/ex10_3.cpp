#include <iostream>
#include <numeric>
#include <vector>
int main()
{
    std::vector<double> v{ 1.3, 2, 3.3, 4, 5 };
    double sum = std::accumulate(v.cbegin(), v.cend(), 0.0);;
    std::cout << sum << std::endl;
    return EXIT_SUCCESS;
}