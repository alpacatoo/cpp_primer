#include <iostream>
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main()
{
    struct Sales_data total;//保存下一条交易记录的变量
    double price = 0.0;
    if (std::cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        struct Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.revenue += trans.units_sold * price;
                total.units_sold += trans.units_sold;
            }
            else
            {   //打印前一本书的结果
                std::cout << total.bookNo << " " << total.units_sold << " "
                    << total.revenue << " " << total.revenue / total.units_sold
                    << std::endl;
            }
        }
        //打印最后一本书结果
        std::cout << total.bookNo << " " << total.units_sold << " "
            << total.revenue << " " << total.revenue / total.units_sold << std::endl;
    }
    else
    {
        std::cout << "No data!!" << std::endl;
    }
    return 0;
}