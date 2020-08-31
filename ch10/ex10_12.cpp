#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
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
    double avg_price(){ return units_sold ? (revenue / units_sold) : 0; }

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
bool compareIsbn(const Sales_data &s1, const Sales_data &s2)
{
    return s1.isbn().size() < s2.isbn().size();
}
int main()
{
    vector<Sales_data> v{ Sales_data("aa"), Sales_data("aaaa"), Sales_data("as"), Sales_data("1111"), Sales_data("ks") };
    std::sort(v.begin(), v.end(), compareIsbn);
    for (auto &s : v)
        std::cout << s.isbn() << std::endl;
}