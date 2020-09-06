#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include "Sales_item.h"

int main()
{
    std::istream_iterator<Sales_item> in_iter(std::cin), in_eof;
    std::vector<Sales_item> vec;

    while (in_iter != in_eof)
        vec.push_back(*in_iter++);
    std::cout << "origin: " << vec.size() << std::endl;
    for (auto v : vec)
        std::cout << v << std::endl;
    std::sort(vec.begin(), vec.end(), compareIsbn);
    std::cout << "sorted:" << std::endl;
    for (auto v : vec)
        std::cout << v << std::endl;
    std::cout << "accumulated:" << std::endl;
    for (auto beg = vec.cbegin(), end = beg; beg != vec.cend(); beg = end) {
        end = find_if(beg, vec.cend(), [beg](const Sales_item &item){ return item.isbn() != beg->isbn(); });
        std::cout << std::accumulate(beg, end, Sales_item(beg->isbn())) << std::endl;
    }
}