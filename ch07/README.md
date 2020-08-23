## 练习7.1

> 使用2.6.1节里纳西定义的Sales_data类为1.6节的交易处理程序编写一个新版本。

```C++
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
```

运行结果：

>0-201 3 20.00
>0-201 2 25.00
>^Z
>0-201 5 110 22
>请按任意键继续. . .



## 练习7.2

> 曾在2.6.2节的练习中编写了一个Sales_data类，请向这个类添加combine和isbn成员。

```C++
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
```



## 练习7.3

> 修改7.1.1节的交易处理程序，令其使用这些成员。

```C++
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
            }
            total = trans;
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
```

运行结果：

>0-201 3 20.00
>0-201 2 25.00
>^Z
>0-201 5 110 22
>请按任意键继续. . .



## 练习7.4

> 编写一个名为Persion的类，使其表示人员的姓名和住址。使用string对象存放这些元素，接下俩的练习将不断填充这个类的其他特征。

```C++
#include <string>
struct Person{
    std::string name;
    std::string address;
}
```



## 练习7.5

> 在你的Persion类中提供一些操作十七能够返回姓名和住址。这些函数是否应该是const的呢？解释原因

应该是const的，因为常量对象也需要这些操作

```C++
#include <string>
struct Person{
   	std::string name;
    std::string address;
    
    const std::string& get_name() const;
    const std::string& get_address() const;
}
```



## 练习7.6

> 对于函数add、read、print，定义你自己的版本。

```C++
struct Sales_data{
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &input);

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
```



## 练习7.7

>使用这些新函数重写7.1.2节练习中的交易处理程序。

```C+
int main()
{
    Sales_data total;
    if (read(std::cin, total))
    {
        Sales_data trans;
        while (read(std::cin, trans))
        {
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
        std::cerr << "No Data!" << std::endl;
        return -1;
    }
    return 0;
}
```

运行结果：

>0-201 3 20.00
>0-201 2 25.00
>^Z
>0-201 5 110 22
>请按任意键继续. . .



## 练习7.8

> 为什么read函数将其Sales_date参数定义成普通引用，而print将其参数定义成常量引用？

因为`read`函数会改变对象的内容，而`print`函数不会。



## 练习7.9

> 对于7.1.2节练习中的代码，添加读取和打印Person对象的操作。

```C++
#include <string>
#include <iostream>
struct Person{
   	std::string name;
    std::string address;
    
    const std::string& get_name() const;
    const std::string& get_address() const;
}
std::istream& read(std::istream &in, Person &item)
{
    return in >> item.name >> item.address;
}
std::ostream& print(std::ostream &out, const Person &person)
{
    return out << person.name << " " << person.address;
}
```



## 练习7.10

> 在下面这天if语句中，条件部分的作用是什么？
>
> ```C++
> if (read(read(cin, data1), data2))
> ```

`read`函数的返回值是`istream`对象，`if`语句中条件部分的作用是从输入流中读取数据给两个`data`对象。



## 练习7.11

> 在你的Sales_data类中添加构造函数，然后编写一段程序令其用到每个构造函数。

```C++
#include <iostream>
#include <string>
struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string&s) :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is);

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &input);

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
Sales_data::Sales_data(std::istream &is)
{
    read(is, *this);
}
int main()
{
    Sales_data item1;
    print(std::cout, item1) << std::endl;

    Sales_data item2("0-201-78345-X");
    print(std::cout, item2) << std::endl;

    Sales_data item3("0-201-78345-X", 3, 20.00);
    print(std::cout, item3) << std::endl;

    Sales_data item4(std::cin);
    print(std::cout, item4) << std::endl;

    return 0;
}
```

运行结果：

>  0 0 -1.#IND
> 0-201-78345-X 0 0 -1.#IND
> 0-201-78345-X 3 60 20
> 0-202 3 20.00
> 0-202 3 60 20
> 请按任意键继续. . .



## 练习7.12

> 把只接受一个istream作为参数的构造函数定义一道类的内部。

```C++
#include <iostream>
#include <string>
struct Sales_data;
std::istream& read(std::istream &in, Sales_data &item);
struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string&s) :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &input);

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
```



## 练习7.13

> 使用istream构造函数重写第229页的程序。

```C++
#include <iostream>
#include <string>
struct Sales_data;
std::istream& read(std::istream &in, Sales_data &item);
struct Sales_data{
    Sales_data() = default;
    Sales_data(const std::string&s) :bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data(std::istream &is) { read(is, *this); }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &input);

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
```

运行结果：

> 0-201 3 20.00
> 0-201 2 25.00
> ^Z
> 0-201 5 110 22
> 请按任意键继续. . .



## 练习7.14

> 编写一个构造函数，令其用我们提供的类内初始值显式地初始化成员。

```C++
Sales_data() : booNo("0-000-00000-0"), units_sold(0) , revenue(0) { }
```



## 练习7.15

> 为你的Person类添加恒却的构造函数。

```C++
#include <string>
#include <iostream>

struct Person;
std::istream &read(std::istream&, Person&);

struct Person
{
	Person() = default;
	Person(const std::string& sname, const std::string& saddr) :name(sname), address(saddr) {}
	Person(std::istream &is) { read(is, *this); }

	std::string getName() const { return name; }
	std::string getAddress() const { return address; }

	std::string name;
	std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name << " " << person.address;
	return os;
}
```



## 练习7.16

> 在类的定义中对于访问说明符出现的位置和次数有限定吗？如果有，是什么？什么样的成员应该定义在public说明符之后？什么样的成员应该定义在private说明符之后？

在类的定义中对于访问说明符出现的位置和次数**没有限定**。
如果某个成员能够在整个程序内都被访问，那么它应该定义为`public`; 
如果某个成员只能在类内部访问，那么它应该定义为`private`。



## 练习7.17

> 使用class和struct时有区别吗？如果有，是什么区别？

有。class的默认访问权限是private，struct的默认访问权限是public。



## 练习7.18

> 封装是何含义？它有什么用处？

将类内部分成员设置为外部不可见，而提供部分接口给外面，这样的行为叫做封装。

作用：（1）用户代码不会破坏封装对象；（2）实现可以变化，但接口可以不变化



## 练习7.19

> 在你的Person类中，你将把哪些成员声明成public的？哪些声明成private的？解释原因。

private：address，name成员变量

public：get之类的函数，构造函数

数据外部不可见，通过get之类的函数调用获得



## 练习7.20

> 友元在生么时候有用？请分别列举出使用友元的利弊。

当其他类或者函数想要访问当前类的私有变量时，这个时候应该用友元。

利：与当前类有关的接口函数能直接访问类的私有变量。

弊：牺牲了封装性与可维护性。



## 练习7.21

> 修改你的Sales_data类使其隐藏实现的细节。你之前编写的关于Sales_data操作的陈鼓型应该据徐使用，借助类的新定义重新编译该程序，确保其工作正常。

```C++
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
```

运行结果：

> 0-201 3 20.00
> 0-201 2 25.00
> ^Z
> 0-201 5 110 22
> 请按任意键继续. . .



## 练习7.22

> 修改你的Person类使其隐藏实现的细节。

```C++
#include <string>
#include <iostream>

class Person;
std::istream &read(std::istream&, Person&);

class Person
{
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream &print(std::ostream &os, const Person &person);
public:
	Person() = default;
	Person(const std::string& sname, const std::string& saddr) :name(sname), address(saddr) {}
	Person(std::istream &is) { read(is, *this); }

	std::string getName() const { return name; }
	std::string getAddress() const { return address; }
    
private:
	std::string name;
	std::string address;
};

std::istream &read(std::istream &is, Person &person)
{
	is >> person.name >> person.address;
	return is;
}

std::ostream &print(std::ostream &os, const Person &person)
{
	os << person.name << " " << person.address;
	return os;
}
```



## 练习7.23

> 编写你自己的Screen类

```C++
#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```



## 练习7.24 

> 给你的Screen类添加三个构造函数：一个默认构造函数；另一个构造函数接受宽和高的值，然后将contents初始化成给定数量的空白；第三个构造函数接受宽和高以及一个字符，该字符初作为初始化后屏幕的内容。

```C++
#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos w, pos h) :width(w), height(h), contents(w*h, ' '){}
    Screen(pos w, pos h, char c) :width(w), height(h), contents(w*h, c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
```



## 练习7.25

> Screen能安全地依赖于拷贝和赋值操作的默认版本吗？如果能，为什么？如果不能，为什么？

能。 `Screen`的成员只有内置类型和`string`，因此能安全地依赖于拷贝和赋值操作的默认版本。没有使用到除去`string`之外的类外动态空间。



## 练习7.26

> 将Sales_data::avg_price定义成内联函数。

在类内定义

```C++
double avg_price(){ return units_sold ? (revenue / units_sold):0; }
```



## 练习7.27

> 给自己的Screen类添加move、set和display函数，通过执行下面的代码验证你的类是正确的。
>
> ```C++
> Screen myScreen(5, 5, 'X');
> myScreen.move(4,0).set('#').display(cout);
> cout << "\n";
> myScreen.display(cout);
> cout << "\n";
> ```

```C++
#include <iostream>
#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos w, pos h) :width(w), height(h), contents(w*h, ' '){}
    Screen(pos w, pos h, char c) :width(w), height(h), contents(w*h, c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen& move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen& set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen& display(std::ostream &output)
    {
        do_display(output);
        return *this;
    }
    const Screen& display(std::ostream &output) const
    {
        do_display(output);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &output) const { output << contents; }
};
```

运行结果：

> XXXXXXXXXXXXXXXXXXXX#XXXX
> XXXXXXXXXXXXXXXXXXXX#XXXX
> 请按任意键继续. . .



## 练习7.28

> 如果move、set和displya函数的返回类型不是Screen&而是Screen则在上一个练习中会发生什么情况?

如果返回类型是`Screen`，那么`move`返回的是`*this`的一个副本，因此`set`函数只能改变临时副本而不能改变`myScreen`的值。



## 练习7.29

> 修改你的Screen类，令move、set和display函数返回Screen并检查程序的运行结果，在上一个练习中你的推测正确吗？

运行结果：

> XXXXXXXXXXXXXXXXXXXX#XXXX
> XXXXXXXXXXXXXXXXXXXXXXXXX
> 请按任意键继续. . .



## 练习7.30

> 通过this指针使用成员的做法虽然合法，但是有点多余。讨论显式地使用指针访问成员的优缺点。

优点：

程序的意图更明确

函数的参数可以与成员同名，如

```cpp
  void setAddr(const std::string &addr) { this->addr = addr; }
```

缺点：

有时候显得有点多余，如

```cpp
std::string getAddr() const { return this->addr; }
```



## 练习7.31 

> 定义一对类X和Y，其中X包含一个指向Y的指针，而Y包含一个类型为X的对象。

```C++
class Y;
class X
{
    Y * y;
};
class Y
{
    X x;
};
```



## 练习7.32

> 定义你自己的Screen和Window_mgs，其中clear是Window_mgr的成员，是Screen的友元。

```C++
#include <string>
#include <vector>
class Screen;
class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};
class Screen{
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos w, pos h) :width(w), height(h), contents(w*h, ' '){}
    Screen(pos w, pos h, char c) :width(w), height(h), contents(w*h, c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen& move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen& set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen& display(std::ostream &output)
    {
        do_display(output);
        return *this;
    }
    const Screen& display(std::ostream &output) const
    {
        do_display(output);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &output) const { output << contents; }
};
inline void Window_mgr::clear(ScreenIndex index)
{
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}
```



## 练习7.33

> 如果我们给Screen添加一个如下所示的size成员将发生什么情况？如果出现了维妮塔，请尝试修改它。
>
> ```C++
> pos Screen::size() const
> {
>     return height * width;
> }
> ```

错误信息：

> 错误	1	error C2143: 语法错误 : 缺少“;”(在“Screen::size”的前面)	c:\users\chris\desktop\cpp\cpp_primer\ch07\ex7_33.cpp	57	1	cpp_primer

修改内容：

```C++
Screen::pos Screen::size() const
{
    return height * width;
}
```



## 练习7.34

> 如果我们把第256页Screen类的pos的typedef放在类的最后一行会发生什么？

函数中会出现 未定义的标识符pos。

类型名的定义通常出现在类的开始处，这样就能确保所有使用该类型的成员都出现在类名的定义之后。



## 练习7.35

> 解释下面代码的含义，说明其中的Type和initVal分别使用了哪个定义。如果代码存在错误，尝试修改它。
>
> ```C++
> typedef string Type;
> Type initVal();
> class Exercise{
> public:
>     typedef double Type;
>     Type setVal(Type);
>     Type initVal();
> private:
>     int val;
> };
> Type Exercise::setVal(Type parm)
> {
>     val = parm + initVal();
>     return val;
> }
> ```

`Type Exercise::setVal(Type parm)`修改成`Exercise::Type Exercise::setVal(Type parm)·



## 练习7.36

> 下面的初始值是错误的，请找出问题所在并尝试修改它。
>
> ```C++
> struct X {
>     X (int i, int j): base(i), rem(base%j){}
>     int rem, base;
> }
> ```

初始化rem时，base还未初始化，修改为：

```C++
struct X {
    X (int i, int j): base(i), rem(base%j){}
    int base, rem;
}
```



## 练习7.37 

> 使用本节提供的Sales_data类，确定初始化下面的变量时分别使用了哪个构造函数，然后罗列出每个对象成员的值。
>
> ```C++
> Sales_data first_iterm(cin);
> int main()
> {
>     Sales_data next;
>     Sales_data last("9-999-99999-9")
> }
> ```

first_iterm：使用 Sales_data(std::istream &is)；各成员值从输入流中读取
next：使用默认构造函数，bookNo=“”；cnt = 0；rvenue = 0.0
last：使用 Sales_data(std::string s = "");   bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0



## 练习7.38

> 有些情况下我们希望提供`cin`作为接受`istream&`参数的构造函数的默认实参，请声明这样的构造函数。

```C++
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```



## 练习7.39

> 如果接受`string`的构造函数和接受`istream&`的构造函数都使用默认实参，这种行为合法吗？如果不，为什么？

不合法。当你调用`Sales_data()`构造函数时，无法区分是哪个重载。



## 练习7.40

> 从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
>
> ```
> (a) Book
> (b) Data
> (c) Employee
> (d) Vehicle
> (e) Object
> (f) Tree
> ```
>

```C++
#include <string>
class Book
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :m_isbn(isbn), m_name(name), m_author(author), m_pubdate(pubdate)
    { }

    explicit Book(std::istream &in)
    {
        in >> m_isbn >> m_name >> m_author >> m_pubdate;
    }

private:
    unsigned m_isbn;
    std::string m_name;
    std::string m_author;
    std::string m_pubdate;
};
```



## 练习7.41 

> 使用委托构造函数重新编写你的`Sales_data`类，给每个构造函数体添加一条语句，令其一旦执行就打印一条信息。用各种可能的方式分别创建`Sales_data`对象，认真研究每次输出的信息直到你确实理解了委托构造函数的执行顺序。

```C++
#include <iostream>
#include <string>
class Sales_data;
std::istream& read(std::istream &in, Sales_data &item);
class Sales_data{
    friend Sales_data& Sales_data::combine(const Sales_data &input);
    friend std::istream& read(std::istream &in, Sales_data &item);
    friend std::ostream& print(std::ostream &out, const Sales_data &item);
public:
    Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p)
    {
        std::cout << "Sales_data(const std::string&, unsigned, double)" << std::endl;
    }
    Sales_data() : Sales_data("", 0, 0.0f)
    {
        std::cout << "Sales_data()" << std::endl;
    }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f)
    {
        std::cout << "Sales_data(const std::string&)" << std::endl;
    }
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
```



## 练习7.42

> 对于你在练习7.40中编写的类，确定哪些构造函数可以使用委托。如果可以的话，编写委托构造函数。如果不可以，从抽象概念列表中重新选择一个你认为可以使用委托构造函数的，为挑选出的这个概念编写类定义。

```C++
#include <string>
class Book
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :m_isbn(isbn), m_name(name), m_author(author), m_pubdate(pubdate)
    { }
    
    Book(unsigned isbn) : Book(isbn, "", "", "") {}

    explicit Book(std::istream &in)
    {
        in >> m_isbn >> m_name >> m_author >> m_pubdate;
    }

private:
    unsigned m_isbn;
    std::string m_name;
    std::string m_author;
    std::string m_pubdate;
};
```



## 练习7.43

> 假定有一个名为`NoDefault`的类，它有一个接受`int`的构造函数，但是没有默认构造函数。定义类`C`，`C`有一个 `NoDefault`类型的成员，定义`C`的默认构造函数。

```C++
class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public:
    C() : def(0) { } 
private:
    NoDefault def;
};
```



## 练习7.44

> 下面这条声明合法吗？如果不，为什么？
>
> ```C++
> vector<NoDefault> vec(10);//vec初始化有10个元素
> ```

不合法，NoDefault没有默认构造函数



## 练习7.45

> 如果在上一个练习中定义的vector的元素类型是C，则声明合法吗？为什么？

合法。因为`C`有默认构造函数。



## 练习7.46 

> 下面哪些论断是不正确的？为什么？
>
> - (a) 一个类必须至少提供一个构造函数。
> - (b) 默认构造函数是参数列表为空的构造函数。
> - (c) 如果对于类来说不存在有意义的默认值，则类不应该提供默认构造函数。
> - (d) 如果类没有定义默认构造函数，则编译器将为其生成一个并把每个数据成员初始化成相应类型的默认值。

（a）不正确，可以使用合成的默认构造函数

（b）不完全正确。为每个参数都提供了默认值的构造函数也是默认构造函数。

（c）不正确。哪怕没有意义的值也需要初始化。

（d）不正确。只有当一个类没有定义**任何构造函数**的时候，编译器才会生成一个默认构造函数。



## 练习7.47

> 说明接受一个`string`参数的`Sales_data`构造函数是否应该是`explicit`的，并解释这样做的优缺点。

是否需要从`string`到`Sales_data`的转换依赖于我们对用户使用该转换的看法。在此例中，这种转换可能是对的。`null_book`中的`string`可能表示了一个不存在的`ISBN`编号。

优点：可以抑制构造函数定义的隐式转换；缺点：为了转换要显式地使用构造函数



## 练习7.48

> 假定`Sales_data`的构造函数不是`explicit`的，则下述定义将执行什么样的操作？
>
> ```C++
> string null_isbn("9-999-9999-9");
> Sales_data item1(null_isbn);
> Sales_data item2("9-999-99999-9");
> ```
>
> 如果`Sales_data`的构造函数时explicit的，又会发生什么呢？

这些定义和是不是`explicit`的无关。



## 练习7.49

> 对于`combine`函数的三种不同声明，当我们调用`i.combine(s)`时分别发生什么情况？其中`i`是一个`Sales_data`，而` s`是一个`string`对象。
>
> ```C++
> (a) Sales_data &combine(Sales_data); 
> (b) Sales_data &combine(Sales_data&);
> (c) Sales_data &combine(const Sales_data&) const;
> ```

（a）隐式类型转换

（b）error C2664: 无法将参数 1 从“std::string”转换为“Sales_data &”	因为隐式转换只有一次

（c）该成员函数是const 的，意味着不能改变对象。而 combine函数的本意就是要改变对象



## 练习7.50

> 确定在你的`Person`类中是否有一些构造函数应该是`explicit` 的。

```C++
explicit Person(std::istream &is){ read(is, *this); }
```



## 练习7.51

> `vector`将其单参数的构造函数定义成`explicit`的，而`string`则不是，你觉得原因何在？

```C++
int getSize(const std::vector<int>&);
getSize(34); //返回34，如果可以隐式转换，创建34个元素的临时变量
```

String变量需要与C风格字符串兼容，将C分隔字符串隐式转换



## 练习7.52

> 使用2.6.1节的 `Sales_data` 类，解释下面的初始化过程。如果存在问题，尝试修改它。
>
> ```C++
> Sales_data item = {"987-0590353403", 25, 15.99};
> ```

`Sales_data` 类不是聚合类，应该修改成如下：

```C++
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```



## 练习7.53

> 定义你自己的`Debug`。

```C++
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b){}
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){}
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b){ io = b; }
    void set_hw(bool b){ hw = b; }
    void set_otehr(bool b) { hw = b; }
private:
    bool hw;
    bool io;
    bool other;
};
```



## 练习7.54

> `Debug`中以 `set_` 开头的成员应该被声明成`constexpr` 吗？如果不，为什么？

不能。`constexpr`函数必须包含一个返回语句。



## 练习7.55

> 7.5.5节的`Data`类是字面值常量类吗？请解释原因。

不是。因为`std::string`不是字面值类型。



## 练习7.56

> 什么是类的静态成员？它有何优点？静态成员与普通成员有何区别？

类的静态成员是类中与类本身直接相关，而不是与类的各个对象保持相关。

静态成员可以声明为自己的类类型；非静态成员只能是自己类类型的指针或引用

静态成员可以作为类的默认实参，普通成员不能。



## 练习7.57

> 编写你自己的`Account`类。

```C++
class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
    
private:
    std::string owner;
    double amount;
    static double interestRate;
    static constexpr double todayRate = 42.42;
    static double initRate() { return todayRate; }
};

double Account::interestRate = initRate();

```



## 练习7.58

> 下面的静态数据成员的声明和定义有错误吗？请解释原因。
>
> ```cpp
> //example.h
> class Example {
> public:
> 	static double rate = 6.5;
> 	static const int vecSize = 20;
> 	static vector<double> vec(vecSize);
> };
> 
> //example.c
> #include "example.h"
> double Example::rate;
> vector<double> Example::vec;
> ```
>

`rate`应该是一个**常量表达式**。而类内只能初始化整型类型的静态常量，所以不能在类内初始化`vec`。修改后如下：

```C++
// example.h
class Example {
public:
    static constexpr double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec;
};

// example.C
#include "example.h"
constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
```







































