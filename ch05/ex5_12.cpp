#include <iostream>
#include <cctype>
int main()
{
    char c, prech = '\0';
    int cnt = 0, flcnt = 0;
    while (std::cin >> c)
    {
        switch (c)
        {
        case 'f':
        case 'i':
        case 'l':
            if (prech == 'f') ++flcnt;
            break;
        }
        prech = c;
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
    std::cout << "Number of ff, fl, fi is " << flcnt << std::endl;
}