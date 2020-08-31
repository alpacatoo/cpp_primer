# 第10章 泛型算法



## 练习10.1

> 头文件`algorithm`中定义了一个名为`count`的函数，它类似`find`， 接受一对迭代器和一个值作为参数。`count`返回给定值在序列中出现的次数。编写程序，读取`int`序列存入`vector`中，打印有多少个元素的值等于给定值。

```C++
#include <iostream>
#include <algorithm>
#include <vector>
int main()
{
    std::vector<int> v{ 2, 1, 5, 3, 7, 4, 2, 4, 6, 2 };
    std::cout << std::count(v.cbegin(), v.cend(), 2) << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 3
> 请按任意键继续. . .



## 练习10.2

> 重做上一题，但读取 `string` 序列存入 `list` 中。

```C++
#include <iostream>
#include <algorithm>
#include <list>
#include <string>
int main()
{
    std::list<std::string> list{ "aaa", "aa", "cc", "bb", "aaa", "ee", "aaa" };
    std::cout << std::count(list.cbegin(), list.cend(), "aaa") << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 3
> 请按任意键继续. . .



## 练习10.3

> 用 `accumulate`求一个 `vector<int>` 中元素之和。

```C++
#include <iostream>
#include <numeric>
#include <vector>
int main()
{
    std::vector<double> v{ 1.3, 2, 3.3, 4, 5 };
    double sum = std::accumulate(v.cbegin(), v.cend(), 0.0);;
    std::cout << sum << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 15.6
> 请按任意键继续. . .



## 练习10.4

> 假定 `v` 是一个`vector<double>`，那么调用 `accumulate(v.cbegin(),v.cend(),0)` 有何错误（如果存在的话）？

结果会是 `int` 类型。泛型算法，结果与第三个参数一致。



## 练习10.5

> 在本节对名册（`roster`）调用`equal`的例子中，如果两个名册中保存的都是C风格字符串而不是`string`，会发生什么？

C风格字符串是用指向字符的指针表示的，因此会比较两个指针的值（地址），而不会比较这两个字符串的内容。



## 练习10.6

> 编写程序，使用 `fill_n` 将一个序列中的 `int` 值都设置为0。

```C++
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::fill_n(vec.begin(), vec.size(), 0);

    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 0 0 0 0 0 0 0 0 0 0
> 请按任意键继续. . .



## 练习10.7

> 下面程序是否有错误？如果有，请改正：
>
> ```C+
> (a) vector<int> vec; list<int> lst; int i;
> 	while (cin >> i)
> 		lst.push_back(i);
> 	copy(lst.cbegin(), lst.cend(), vec.begin());
> (b) vector<int> vec;
> 	vec.reserve(10);
> 	fill_n(vec.begin(), 10, 0);
> ```

(a) 应该加一条语句 `vec.resize(lst.size())` 。`copy`时必须保证目标目的序列至少要包含与输入序列一样多的元素。

(b) 从语句上来说没错误，这段代码没有任何结果。但是从逻辑上来说，应该将 `vec.reserve(10)` 改为 `vec.resize(10)` 。



## 练习10.8

> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 `back_inserter`不会使这一断言失效？

`back_inserter` 是插入迭代器，在 `iterator `头文件中，不是标准库的算法。



## 练习10.9

> 实现你自己的`elimDups`。分别在读取输入后、调用`unique`后以及调用`erase`后打印`vector`的内容。

```C++
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
int main()
{
    std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    std::sort(vs.begin(), vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    auto iter = std::unique(vs.begin(), vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    vs.erase(iter, vs.end());

    for (auto &c : vs)
        std::cout << c << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
```

运行结果：

> a v a s v a a
> a a a a s v v
> a s v a   v
> a s v
> 请按任意键继续. . .



## 练习10.10

> 你认为算法不改变容器大小的原因是什么？

算法的参数是迭代器，不是容器本身。



## 练习10.11

> 编写程序，使用 `stable_sort` 和 `isShorter` 将传递给你的 `elimDups` 版本的 `vector` 排序。打印 `vector`的内容，验证你的程序的正确性。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
int main()
{
    vector<string> v{ "1234", "272", "1111", "1234", "783", "222" };
    elimDups(v);
    stable_sort(v.begin(), v.end(), isShorter);
    for (auto s: v)
        cout << s << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

>222
>272
>783
>1111
>1234
>请按任意键继续. . .



## 练习10.12

> 编写名为 `compareIsbn` 的函数，比较两个 `Sales_data` 对象的`isbn()` 成员。使用这个函数排序一个保存 `Sales_data` 对象的 `vector`。

```C++
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
```

运行结果：

> aa
> as
> ks
> aaaa
> 1111
> 请按任意键继续. . .



## 练习10.13

> 标准库定义了名为 `partition` 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为`true` 的值会排在容器的前半部分，而使得谓词为 `false` 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 `true` 的元素之后的位置。编写函数，接受一个 `string`，返回一个 `bool` 值，指出 `string` 是否有5个或更多字符。使用此函数划分 `words`。打印出长度大于等于5的元素。

```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool chNum(const string &s)
{
    return s.size() >= 5 ? true : false;
}
int main()
{
    vector<string> v{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto par_end = partition(v.begin(), v.end(), chNum);
    for (auto curr = v.begin(); curr != par_end; ++curr)
        cout << *curr << endl;
    return EXIT_SUCCESS;
}
```

运行结果；

> aaaaaabba
> aaaaassaa
> aasss
> 请按任意键继续. . .



