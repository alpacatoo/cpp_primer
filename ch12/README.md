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



## 练习12.10

> 下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？
>
> ```C++
> shared_ptr<int> p(new int(42));
> process(shared_ptr<int>(p));
> ```

正确。`shared_ptr<int>(p)` 会创建一个临时的智能指针，这个智能指针与 p 引用同一个对象，此时引用计数为 2。当表达式结束时，临时的智能指针被销毁，此时引用计数为 1。



## 练习12.11

> 如果我们像下面这样调用 process，会发生什么？
>
> ```C++
> process(shared_ptr<int>(p.get()));
> ```

这样会创建一个新的智能指针，它的引用计数为 1，这个智能指针所指向的空间与 p 相同。在表达式结束后，这个临时智能指针会被销毁，引用计数为 0，所指向的内存空间也会被释放。而导致 p 所指向的空间被释放，使得 p 成为一个空悬指针。



## 练习12.12

> p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
>
> ```C++
> auto p = new int();
> auto sp = make_shared<int>();
> (a) process(sp);
> (b) process(new int());
> (c) process(p);
> (d) process(shared_ptr<int>(p));
> ```

p是内置指针，且执行默认初始化；sp是智能指针，执行值初始化
(a) 合法。将sp 拷贝给 process函数的形参，在函数里面引用计数为 2，函数结束后引用计数为 1。
(b) 不合法。不能从内置指针隐式转换为智能指针。
(c) 不合法。不能从内置指针隐式转换为智能指针。
(d) 合法。但是智能指针和内置指针一起使用可能会出现问题，在表达式结束后智能指针会被销毁，它所指向的对象也被释放。而此时内置指针 p 依旧指向该内存空间。之后对内置指针 p 的操作可能会引发错误。



## 练习12.13

> 如果执行下面的代码，会发生什么？
>
> ```C++
> auto sp = make_shared<int>();
> auto p = sp.get();
> delete p;
> ```

智能指针 sp 所指向空间已经被释放，再对 sp 进行操作会出现错误。



## 练习12.14

> 编写你自己版本的用 shared_ptr 管理 connection 的函数。

```C++
#include <iostream>
#include <memory>
#include <string>

struct connection
{
    std::string ip;
    int port;
    connection(std::string i, int p) :ip(i), port(p){}
};

struct destination
{
    std::string ip;
    int port;
    destination(std::string i, int p) :ip(i), port(p){}
};

connection connect(destination *pd)
{
    std::shared_ptr<connection> pConn(new connection(pd->ip, pd->port));
    std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
    std::cout << "creating connection object address: " << pConn.get() << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    std::cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << std::endl;
}

void end_connection(connection* pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    std::cout << "object address: " << &conn << std::endl;
    std::shared_ptr<connection> p(&conn, end_connection);
    std::cout << "connecting now(" << p.use_count() << ")" << std::endl;
}

int main()
{
    destination dest("192.168.3.3", 8888);
    f(dest);
    return EXIT_SUCCESS;
}
```

运行结果：

> creating connection(1)
> creating connection object address: 01618C70
> object address: 012FF820
> connecting now(1)
> connection close(192.168.3.3:8888)
> 请按任意键继续. . .



## 练习12.15

> 重写第一题的程序，用 lambda 代替end_connection 函数。

删除end_connection函数，并将

```C++
std::shared_ptr<connection> p(&conn, end_connection);
```

替换为

```C++
std::shared_ptr<connection> p(&conn, [](connection* p){ disconnect(*p); });
```

运行结果：

> creating connection(1)
> creating connection object address: 01558E60
> object address: 012FFD68
> connecting now(1)
> connection close(192.168.3.3:8888)
> 请按任意键继续. . .