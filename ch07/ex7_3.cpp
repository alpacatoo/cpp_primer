#include <iostream>
#include <string>
struct Sales_data{
    std::string isbn() const { return bookNo; }
    Sales_data& combine(Sales_data &input);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data& Sales_data::combine(Sales_data &input)
{
    units_sold += input.units_sold;
    revenue += input.revenue;
    return *this;
}
int main()
{
    Sales_data total;
    double price = 0.0;
    if (std::cin >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = price * total.units_sold;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price)
        {
            trans.revenue = price * trans.units_sold;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                std::cout << total.isbn() << " " << total.units_sold << " "
                    << total.revenue << " " << total.revenue / total.units_sold
                    << std::endl;
                total = trans;
            }
        }
        std::cout << total.isbn() << " " << total.units_sold << " "
            << total.revenue << " " << total.revenue / total.units_sold
            << std::endl;
    }
    else
    {
        std::cerr << "No Data!" << std::endl;
    }
    return 0;
}