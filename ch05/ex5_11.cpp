#include <iostream>
#include <cctype>
int main()
{
    char c;
    int cnt = 0;
    while (std::cin >> c)
    {
        if (isalpha(c))
            c = tolower(c);
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case ' ':
        case '\t':
        case '\n':
            ++cnt;
        }
    }
    std::cout << "Number of vowel is " << cnt << std::endl;
}