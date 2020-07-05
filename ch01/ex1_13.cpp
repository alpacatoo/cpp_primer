#include <iostream>

int main()
{
    std::cout << "Exercise 1.9" << std::endl;
    int sum1_9 = 0;
    for (int i = 50; i <= 100; ++i) sum1_9 += i;
    std::cout << "the sum is: " << sum1_9 << std::endl;

    std::cout << "Exercise 1.10" << std::endl;
    for (int cnt = 10; cnt >= 0; cnt--)
        std::cout << cnt << std::endl;

    std::cout << "Exercise 1.11" << std::endl;
    std::cout << "Input two number:" << std::endl;
    int low = 0, high = 0;
    std::cin >> low >> high;
    if (low > high)
    {
        int temp = high;
        high = low;
        low = temp;
    }
    for (; low <= high; low++)
        std::cout << low << std::endl;
}