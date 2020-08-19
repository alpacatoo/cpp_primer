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

