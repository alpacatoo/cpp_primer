#include <iostream>
#include "Sales_item.h"
//将Sales_item.h和Version_test.h文件放到工程项目中
int main()
{
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl);
    return 0;
}