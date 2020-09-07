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



## 练习10.14

> 编写一个`lambda`，接受两个`int`，返回它们的和。

```C++
auto a = [] (const int a, const int b) {return a+b;};
```



## 练习10.15

> 编写一个 `lambda` ，捕获它所在函数的 `int`，并接受一个 `int`参数。`lambda` 应该返回捕获的 `int` 和 `int` 参数的和。

```C++
int a = 19;
auto f = [a](int b) { return a+b; };
```



## 练习10.16

> 使用 `lambda` 编写你自己版本的 `biggies`。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void elimDups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());
    auto v_uniq = unique(vs.begin(), vs.end());
    vs.erase(v_uniq, vs.end());
}
string make_plural(const int size, const string &s, const string &ending)
{
    return size > 1 ? s + ending : s;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    stable_sort(words.begin(), words.end(),
        [](const string &a, const string &b)
            { return a.size() < b.size(); });
    cout << "stable_sort result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> v{ "a", "aaaaaabba", "bbb", "aa", "bba", "aa", "a", "aaaaaabba", "aaa", "bbb" };
    biggies(v, 2);
    return EXIT_SUCCESS;
}
```

运行结果：

> elimDups result: a aa aaa aaaaaabba bba bbb
> stable_sort result: a aa aaa bba bbb aaaaaabba
> 5 wordss of length 2 or longer
> aa aaa bba bbb aaaaaabba
> 请按任意键继续. . .



## 练习10.17

> 重写10.3.1节练习10.12的程序，在对`sort`的调用中使用 `lambda` 来代替函数 `compareIsbn`。

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
int main()
{
    vector<Sales_data> v{ Sales_data("aa"), Sales_data("aaaa"), Sales_data("as"), Sales_data("1111"), Sales_data("ks") };
    std::sort(v.begin(), v.end(), [](const Sales_data &s1, const Sales_data &s2)
                                        {return s1.isbn().size() < s2.isbn().size(); });
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



## 练习10.18

> 重写 `biggies`，用 `partition` 代替 `find_if`。我们在10.3.1节练习10.13中介绍了 `partition` 算法。

```C++
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
void elimDups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());
    auto v_uniq = unique(vs.begin(), vs.end());
    vs.erase(v_uniq, vs.end());
}
string make_plural(const int size, const string &s, const string &ending)
{
    return size > 1 ? s + ending : s;
}
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = partition(words.begin(), words.end(),
                            [sz](const std::string &s)
                                {return s.size() < sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> v{ "a", "aaaaaabba", "bbb", "aa", "bba", "aa", "a", "aaaaaabba", "aaa", "bbb" };
    biggies_partition(v, 2);
    return EXIT_SUCCESS;
}
```

运行结果：

> elimDups result: a aa aaa aaaaaabba bba bbb
> 5 wordss of length 2 or longer
> aa aaa aaaaaabba bba bbb
> 请按任意键继续. . .



## 练习10.19

> 用 `stable_partition` 重写前一题的程序，与 `stable_sort` 类似，在划分后的序列中维持原有元素的顺序。

```C++
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
void elimDups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());
    auto v_uniq = unique(vs.begin(), vs.end());
    vs.erase(v_uniq, vs.end());
}
string make_plural(const int size, const string &s, const string &ending)
{
    return size > 1 ? s + ending : s;
}
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = stable_partition(words.begin(), words.end(),
        [sz](const std::string &s)
    {return s.size() < sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> v{ "a", "aaaaaabba", "bbb", "aa", "bba", "aa", "a", "aaaaaabba", "aaa", "bbb" };
    biggies_partition(v, 2);
    return EXIT_SUCCESS;
}
```

运行结果：

> elimDups result: a aa aaa aaaaaabba bba bbb
> 5 wordss of length 2 or longer
> aa aaa aaaaaabba bba bbb
> 请按任意键继续. . .



## 练习10.20

> 标准库定义了一个名为 `count_if` 的算法。类似 `find_if`，此函数接受一对迭代器，表示一个输入范围，还接受一个谓词，会对输入范围中每个元素执行。`count_if`返回一个计数值，表示谓词有多少次为真。使用`count_if`重写我们程序中统计有多少单词长度超过6的部分。

```C++
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int bigerthan6(const vector<string> &words)
{
    return count_if(words.begin(), words.end(), [](const string &s)
                                                    {return s.size() > 6; });
}
int main()
{
    vector<string> vs{"dfdf", "kubernetes", "world", "docker", "goodbye"};
    cout << bigerthan6(vs) << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 2
> 请按任意键继续. . .



## 练习10.21

> 编写一个 `lambda`，捕获一个局部 `int` 变量，并递减变量值，直至它变为0。一旦变量变为0，再调用`lambda`应该不再递减变量。`lambda`应该返回一个`bool`值，指出捕获的变量是否为0。

```C++
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int i = 6;
    auto f = [&i]() -> bool{return i > 0 ? --i : i; };
    while (f())
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 5 4 3 2 1
> 请按任意键继续. . .



## 练习10.22

> 重写统计长度小于等于6的单词数量的程序，使用函数代替`lambda`。

```C++
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
bool isLessEqthan6(const string &words, string::size_type sz)
{
    return words.size() <= sz;
}
int main()
{
    vector<string> vs{ "dfdf", "kubernetes", "world", "docker", "goodbye" };
    cout << count_if(vs.cbegin(), vs.cend(), bind(isLessEqthan6, _1, 6)) << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 3
> 请按任意键继续. . .



## 练习10.23

> `bind` 接受几个参数？

假设被绑定的函数接受 `n` 个参数，那么`bind` 接受`n + 1`个参数。



## 练习10.24

> 给定一个`string`，使用 `bind` 和 `check_size` 在一个 `int` 的`vector` 中查找第一个大于`string`长度的值。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;
int check_size(const string &s, const int i)
{
    return i > static_cast<int>(s.size());
}
int main()
{
    vector<int> vi{ 1, 2, 3, 4, 5, 6, 7 };
    string s = "like";
    auto wc = find_if(vi.cbegin(), vi.cend(), bind(check_size, s, _1));
    cout << *wc << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 5
> 请按任意键继续. . .



## 练习10.25

> 在10.3.2节的练习10.18中，编写了一个使用`partition` 的`biggies`版本。使用 `check_size` 和 `bind` 重写此函数。

```C++
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
void elimDups(vector<string> &vs)
{
    sort(vs.begin(), vs.end());
    auto v_uniq = unique(vs.begin(), vs.end());
    vs.erase(v_uniq, vs.end());
}
string make_plural(const int size, const string &s, const string &ending)
{
    return size > 1 ? s + ending : s;
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    cout << "elimDups result: ";
    for (auto s : words)
        cout << s << " ";
    cout << endl;
    auto wc = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
        << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(),
        [](const string &s){cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> v{ "a", "aaaaaabba", "bbb", "aa", "bba", "aa", "a", "aaaaaabba", "aaa", "bbb" };
    biggies_partition(v, 2);
    return EXIT_SUCCESS;
}
```

运行结果：

> elimDups result: a aa aaa aaaaaabba bba bbb
> 5 wordss of length 2 or longer
> aa aaa aaaaaabba bba bbb
> 请按任意键继续. . .



## 练习10.26

> 解释三种插入迭代器的不同之处。

* `back_inserter` 使用 `push_back` 。
* `front_inserter` 使用 `push_front` 。
* `inserter` 使用 `insert`，此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。



## 练习10.27

> 除了 `unique` 之外，标准库还定义了名为 `unique_copy` 的函数，它接受第三个迭代器，表示拷贝不重复元素的目的位置。编写一个程序，使用 `unique_copy`将一个`vector`中不重复的元素拷贝到一个初始化为空的`list`中。

```C++
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;
int main()
{
    //vector<int> vi{ 1, 1, 2, 3, 4, 3, 2, 4, 6, 5, 6, 7, 5 };
    vector<int> vi{ 1, 1, 2, 2, 2, 4, 4, 4, 3, 3, 3 };
    list<int> li;
    //unique只能去除相临重复元素
    unique_copy(vi.cbegin(), vi.cend(), back_inserter(li));
    for (auto i : li)
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 1 2 4 3
> 请按任意键继续. . .



## 练习10.28

> 一个`vector` 中保存 1 到 9，将其拷贝到三个其他容器中。分别使用`inserter`、`back_inserter` 和 `front_inserter` 将元素添加到三个容器中。对每种 `inserter`，估计输出序列是怎样的，运行程序验证你的估计是否正确。

```C++
#include <vector>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
int main()
{
    vector<int> vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> l_back, l_front, l_insert;
    copy(vi.cbegin(), vi.cend(), back_inserter(l_back));
    copy(vi.cbegin(), vi.cend(), front_inserter(l_front));
    copy(vi.cbegin(), vi.cend(), inserter(l_insert,l_insert.begin()));
    for (auto i : l_back)
        cout << i << " ";
    cout << endl;
    for (auto i : l_front)
        cout << i << " ";
    cout << endl;
    for (auto i : l_insert)
        cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 1 2 3 4 5 6 7 8 9
> 9 8 7 6 5 4 3 2 1
> 1 2 3 4 5 6 7 8 9
> 请按任意键继续. . .



## 练习10.29

> 编写程序，使用流迭代器读取一个文本文件，存入一个`vector`中的`string`里。

```C++
#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile("../ch10/book.txt");
    istream_iterator<string> in_iter(infile), eof;
    vector<string> vs(in_iter, eof);
    for (auto s : vs)
        cout << s << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> PS C:\cpp_primer\Debug> .\cpp_primer.exe
> do
> it
> best
> like
> it
> bye
> bye
> PS C:\cpp_primer\Debug>



## 练习10.30

> 使用流迭代器、`sort` 和 `copy` 从标准输入读取一个整数序列，将其排序，并将结果写到标准输出。

```C++
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    cout << "input: " << endl;
    istream_iterator<int> in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(vi));
    sort(vi.begin(), vi.end());
    cout << "output:" << endl;
    copy(vi.cbegin(), vi.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> input:
> 5 4 2 1 6 8
> 9 5 1 2 6 4
> ^Z
> output:
> 1 1 2 2 4 4 5 5 6 6 8 9
> 请按任意键继续. . .



## 练习10.31

> 修改前一题的程序，使其只打印不重复的元素。你的程序应该使用 `unique_copy`。

```C++
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    cout << "input: " << endl;
    istream_iterator<int> in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(vi));
    sort(vi.begin(), vi.end());
    cout << "output:" << endl;
    unique_copy(vi.cbegin(), vi.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> input:
> 5 4 2 1 6 8
> 9 5 1 2 6 4
> ^Z
> output:
> 1 2 4 5 6 8 9
> 请按任意键继续. . .



## 练习10.32

> 重写1.6节中的书店程序，使用一个`vector`保存交易记录，使用不同算法完成处理。使用 `sort` 和10.3.1节中的 `compareIsbn` 函数来排序交易记录，然后使用 `find` 和 `accumulate` 求和。

```C++
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
```

运行结果：

> 0-201-78345-x 3 20.00
> 0-201-70353-x 4 24.99
> 0-201-78345-x 2 25.00
> ^Z
> origin: 3
> 0-201-78345-x 3 60 20
> 0-201-70353-x 4 99.96 24.99
> 0-201-78345-x 2 50 25
> sorted:
> 0-201-78345-x 2 50 25
> 0-201-78345-x 3 60 20
> 0-201-70353-x 4 99.96 24.99
> accumulated:
> 0-201-78345-x 5 110 22
> 0-201-70353-x 4 99.96 24.99
> 请按任意键继续. . .

**Note**：VS编程环境，必须使用Realse编译酝酿下才能有结果。或者设置Debug的选项："Project"->"setting"->"点击c/c++"->"Category选项中选择Preprocessor"
->"，在Undefined symbols:填写_DEBUG" 



## 练习10.33

> 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。输入文件保存的应该是整数。使用 `istream_iterator` 读取输入文件。使用 `ostream_iterator` 将奇数写入第一个输入文件，每个值后面都跟一个空格。将偶数写入第二个输出文件，每个值都独占一行。

```C++
#include <fstream>
#include <iterator>
#include <algorithm>

int main(int argc, char **argv)
{
    if (argc != 4) return -1;

    std::ifstream ifs(argv[1]);
    std::ofstream ofs_odd(argv[2]), ofs_even(argv[3]);

    std::istream_iterator<int> in(ifs), in_eof;
    std::ostream_iterator<int> out_odd(ofs_odd, " "), out_even(ofs_even, "\n");

    std::for_each(in, in_eof, [&out_odd, &out_even](const int i)
    {
        *(i & 0x1 ? out_odd : out_even)++ = i;
    });

    return 0;
}
```

运行程序：

> PS C:\cpp_primer\Release> .\cpp_primer.exe ..\ch10\num.txt ..\ch10\odd.txt ..\ch10\even.txt
> PS C:\cpp_primer\Release>



## 练习10.34

> 使用 `reverse_iterator` 逆序打印一个`vector`。

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto it = v.crbegin(); it != v.crend(); ++it)
    {
        cout << *it << endl;
    }
    return EXIT_SUCCESS;
}
```

运行结果：

> 9
> 8
> 7
> 6
> 5
> 4
> 3
> 2
> 1
> 请按任意键继续. . .



## 练习10.35

> 使用普通迭代器逆序打印一个`vector`。

```C++
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto it = v.cend()-1; true; --it)
    {
        std::cout << *it << " ";
        if (it == v.cbegin()) break;
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 9 8 7 6 5 4 3 2 1
> 请按任意键继续. . .



## 练习10.36

> 使用 `find` 在一个 `int` 的`list` 中查找最后一个值为0的元素。

```C++
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    list<int> l = { 1, 2, 0, 4, 5, 6, 7, 0, 9 };
    auto it = find(l.crbegin(), l.crend(), 0);
    cout << distance(it, l.crend()) << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 8
> 请按任意键继续. . .



## 练习10.37

> 给定一个包含10 个元素的`vector`，将位置3到7之间的元素按逆序拷贝到一个`list`中。

```C++
#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> l;
    copy(v.crbegin() + 3, v.crbegin() + 8, back_inserter(l));
    for (auto i : l) std::cout << i << " ";
    cout << endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 6 5 4 3 2
> 请按任意键继续. . .



## 练习10.38

> 列出5个迭代器类别，以及每类迭代器所支持的操作。

* 输入迭代器 : `==`,`!=`,`++`,`*`,`->`
* 输出迭代器 : `++`,`*`
* 前向迭代器 : `==`,`!=`,`++`,`*`,`->`
* 双向迭代器 : `==`,`!=`,`++`,`--`,`*`,`->`
* 随机访问迭代器 : `==`,`!=`,`<`,`<=`,`>`,`>=`,`++`,`--`,`+`,`+=`,`-`,`-=`,`*`,`->`,`iter[n]`==`*(iter[n])`



## 练习10.39

> `list` 上的迭代器属于哪类？`vector`呢？

* `list` 上的迭代器是 **双向迭代器**
* `vector` 上的迭代器是 **随机访问迭代器**



## 练习10.40

> 你认为 `copy` 要求哪类迭代器？`reverse` 和 `unique` 呢？

* `copy` 需要两个**输入迭代器**，一个**输出迭代器**
* `reverse` 需要**双向迭代器**
* `unique`需要**随机访问迭代器



## 练习10.41

> 仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
>
> ```C++
> replace(beg, end, old_val, new_val);
> replace_if(beg, end, pred, new_val);
> replace_copy(beg, end, dest, old_val, new_val);
> replace_copy_if(beg, end, dest, pred, new_val);
> ```

* `replace` 在迭代器范围内用新值替换所有原来的旧值。
* `replace_if` 在迭代器范围内，满足谓词条件的元素用新值替换。
* `replace_copy` 复制迭代器范围内的元素到目标迭代器位置，如果元素等于某个旧值，则用新值替换
* `replace_copy_if` 复制迭代器范围内的元素到目标迭代器位置，满足谓词条件的元素用新值替换



## 练习10.42

> 使用 `list` 代替 `vector` 重新实现10.2.3节中的去除重复单词的程序。

```c++
#include <iostream>
#include <string>
#include <list>
using namespace std;
void elimDups(list<string> &words)
{
    words.sort();
    words.unique();
}
int main()
{
    list<string> l = { "aa", "aad", "aa", "aa", "aasss", "aa" };
    elimDups(l);
    for (const auto& e : l)
        std::cout << e << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> aa
> aad
> aasss
> 请按任意键继续. . .