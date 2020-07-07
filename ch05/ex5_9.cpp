#include <iostream>
#include <cctype>
int main()
{
    char c;
    int cnt = 0;
    while(std::cin >> c)
    {
        switch (c)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++cnt;
        }
    }
    std::cout << "Number of vowel is " << cnt << std::endl;
}