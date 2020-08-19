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
