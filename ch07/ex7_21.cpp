#include <iostream>
#include <string>
class Sales_data;
std::istream& read(std::istream &in, Sales_data &item);
class Sales_data{
    friend Sales_data& Sales_data::combine(const Sales_data &input);
    friend std::istream& read(std::istream &in, Sales_data &item);
    friend std::ostream& print(std::ostream &out, const Sales_data &item);
public:
    Sales_data() = default;
    Sales_data(const std::string&s) :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &input);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
Sales_data& Sales_data::combine(const Sales_data &input)
{
    units_sold += input.units_sold;
    revenue += input.revenue;
    return *this;
}
std::istream& read(std::istream &in, Sales_data &item)
{
    double price = 0.0;
    in >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return in;
}
std::ostream& print(std::ostream &out, const Sales_data &item)
{
    double price = 0.0;
    out << item.bookNo << " " << item.units_sold << " "
        << item.revenue << " " << item.revenue / item.units_sold;
    return out;
}
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
int main()
{
    std::istream &is = std::cin;
    Sales_data total(is);
    if (is)
    {
        while (is)
        {
            Sales_data trans(is);
            if (!is) break;
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else
    {
        std::cerr << "No data!" << std::endl;
    }
    return 0;
}