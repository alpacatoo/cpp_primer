## 练习12.1

> 在此代码的结尾，b1 和 b2 各包含多少个元素？
>
> ```C++
> StrBlob b1;
> {
> 	StrBlob b2 = {"a", "an", "the"};
> 	b1 = b2;
> 	b2.push_back("about");
> }
> ```

它们实际操作的是同一个vector，都包含4个元素。在代码的结尾，b2 被析构了，不影响 b1 的元素。



## 练习12.2

> 编写你自己的StrBlob 类，包含const 版本的 front 和 back。

```C++
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using std::vector;
using std::string;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;

    StrBlob() :data(std::make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)){}

    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    //添加和删除元素
    void push_back(const string& s)
    {
        data->push_back(s);
    }
    void pop_back() const
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }
    //元素访问
    string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string& front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    std::shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

int main()
{
    StrBlob p{"aa","bb"};
    const StrBlob q{ "ccc", "ddd", "eee" };

    std::cout << "p : " << p.front() << " " << p.back() << std::endl;
    std::cout << "q : " << q.front() << " " << q.back() << std::endl;

    return EXIT_SUCCESS;
}
```

运行结果：

> p : aa bb
> q : ccc eee
> 请按任意键继续. . .



## 练习12.3

> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要。

不需要。`push_back` 和 `pop_back` 会改变对象的内容。而 const 对象是只读的，因此不需要。



## 练习12.4

> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

因为 size_type 是一个无符号整型，当传递给 check 的参数小于 0 的时候，参数值会转换成一个正整数。



## 练习12.5

> 我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。

构造函数不是 explicit 的，意味着可以从 initializer_list 隐式转换为 StrBlob。在 StrBlob 对象中，只有一个数据成员 data，而 StrBlob 对象本身的含义，也是一个**管理字符串的序列**。因此，从 initializer_list 到 StrBlob 的转换，在逻辑上是可行的。而这个设计策略的缺点，可能在某些地方我们确实需要 initializer_list，而编译器仍会将之转换为 StrBlob。



## 练习12.6

> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

```C++
#include <vector>
#include <iostream>
using std::vector;

int main()
{
    auto p = new vector<int>();
    int i;
    while (std::cin >> i)
    {
        p->push_back(i);
    }
    for (auto i : *p)
    {
        std::cout << i << std::endl;
    }
    delete p;
    return EXIT_SUCCESS;
}
```

运行结果：

> 2
> 3
> 4
> ^Z
> 2
> 3
> 4
> 请按任意键继续. . .



## 练习12.7

> 重做上一题，这次使用 shared_ptr 而不是内置指针。

```C++
#include <vector>
#include <iostream>
#include <memory>
using std::vector;
using std::shared_ptr;
using std::make_shared;
int main()
{
    shared_ptr<vector<int>> p = make_shared<vector<int>>();
    int i;
    while (std::cin >> i)
    {
        p->push_back(i);
    }
    for (auto i : *p)
    {
        std::cout << i << std::endl;
    }
    return EXIT_SUCCESS;
}
```

运行结果：

> 2
> 3
> 4
> ^Z
> 2
> 3
> 4
> 请按任意键继续. . .



## 练习12.8

> 下面的函数是否有错误？如果有，解释错误原因。
>
> ```C++
> bool b() {
> 	int* p = new int;
> 	// ...
> 	return p;
> }
> ```

函数的返回类型有问题，应为`bool *`



## 练习12.9

> 解释下面代码执行的结果。
>
> ```C++
> int *q = new int(42), *r = new int(100);
> r = q;
> auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
> r2 = q2;
> ```

r 和 q 指向 42，而之前 r 指向的 100 的内存空间并没有被释放，因此会发生内存泄漏。r2 和 q2 都是智能指针，当对象空间不被引用的时候会自动释放。





