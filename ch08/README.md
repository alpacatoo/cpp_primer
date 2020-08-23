# 第8章 IO库



## 练习8.1

> 编写函数，接受一个`istream&`参数，返回值类型也是`istream&`。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。

```C++
#include <iostream>
#include <string>
std::istream& func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}
```



## 练习8.2

> 测试函数，调用参数为`cin`。

```C++
#include <iostream>
#include <string>
std::istream& func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istream& is = func(std::cin);
    std::cout << is.rdstate() << std::endl;
    return 0;
}
```



## 练习8.3

> 什么情况下，下面的`while`循环会终止？
>
> ```C++
> while (cin >> i) /*  ...    */
> ```

如`badbit`、`failbit`、`eofbit` 的任一个被置位，那么检测流状态的条件会失败。



## 练习8.4

> 编写函数，以读模式打开一个文件，将其内容读入到一个`string`的`vector`中，将每一行作为一个独立的元素存于`vector`中。

```C++
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
void ReadFileToVec(const string &fileName, vector<string> v)
{
    std::ifstream f(fileName, std::fstream::in);
    if (f)
    {
        string str;
        while (std::getline(f, str))
        {
            v.push_back(str);
        }
    }
    
}
```



## 练习8.5

> 重写上面的程序，将每个单词作为一个独立的元素进行存储。

```C++
#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
void ReadFileToVec(const string &fileName, vector<string> v)
{
    std::ifstream f(fileName, std::fstream::in);
    if (f)
    {
        string str;
        while (f >> str)
        {
            v.push_back(str);
        }
    }

}
```



## 练习8.6

> 重写7.1.1节的书店程序，从一个文件中读取交易记录。将文件名作为一个参数传递给`main`。

```C++
#include <iostream>
#include <fstream>
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);

    struct Sales_data total;//保存下一条交易记录的变量
    double price = 0.0;
    if (input >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        struct Sales_data trans;
        while (input >> trans.bookNo >> trans.units_sold >> price)
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



## 练习8.7

> 修改上一节的书店程序，将结果保存到一个文件中。将输出文件名作为第二个参数传递给`main`函数。

```C++
#include <iostream>
#include <fstream>
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

    struct Sales_data total;//保存下一条交易记录的变量
    double price = 0.0;
    if (input >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        struct Sales_data trans;
        while (input >> trans.bookNo >> trans.units_sold >> price)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.revenue += trans.units_sold * price;
                total.units_sold += trans.units_sold;
            }
            else
            {   //打印前一本书的结果
                output << total.bookNo << " " << total.units_sold << " "
                    << total.revenue << " " << total.revenue / total.units_sold
                    << std::endl;
            }
        }
        //打印最后一本书结果
        output << total.bookNo << " " << total.units_sold << " "
            << total.revenue << " " << total.revenue / total.units_sold << std::endl;
    }
    else
    {
        std::cout << "No data!!" << std::endl;
    }
    return 0;
}
```



## 练习8.9

> 使用你为8.1.2节第一个练习所编写的函数打印一个`istringstream`对象的内容。

```C++
#include <iostream>
#include <sstream>
#include <string>
std::istream& func(std::istream &is)
{
    std::string buf;
    while (is >> buf)
        std::cout << buf << std::endl;
    is.clear();
    return is;
}

int main()
{
    std::istringstream ss("hello world!!");
    func(ss);
    return 0;
}
```



## 练习8.10

> 编写程序，将来自一个文件中的行保存在一个`vector`中。然后使用一个`istringstream`从`vector`读取数据元素，每次读取一个单词。

```C++
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
int main()
{
    std::ifstream inputFile("./data.txt");
    if (!inputFile)
    {
        std::cout << "Open file Fail!!" << std::endl;
        return EXIT_FAILURE;
    }

    string bufString;
    vector<string> v;
    while (getline(inputFile, bufString))
    {
        v.push_back(bufString);
    }

    for (auto & s : v)
    {
        std::istringstream iss(s);
        string word;
        while (iss >> word)
        {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
```

运行结果：

```C++
PS C:\\cpp_primer\Debug> .\cpp_primer.exe
Open file Fail!!
PS C:\\cpp_primer\Debug> .\cpp_primer.exe
hello
world!
thank
you.
how
are
you?
```



## 练习8.11

> 本节的程序在外层`while`循环中定义了`istringstream`对象。如果`record`对象定义在循环之外，你需要对程序进行怎样的修改？重写程序，将`record`的定义移到`while`循环之外，验证你设想的修改方法是否正确。

```C++
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
struct PersonInfo{
    string name;
    vector<string> phones;
};
int main()
{
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(std::cin, line))
    {
        PersonInfo info;
        record.clear();     //必须要有这个clear函数
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &phone : p.phones)
            std::cout << phone << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
```

运行结果：

> aaa 152326 451232 125
> bbb 455 585644
> ccc 745456
> ddd 54856 458456 85623
> ^Z
> aaa 152326 451232 125
> bbb 455 585644
> ccc 745456
> ddd 54856 458456 85623
> 请按任意键继续. . .



## 练习8.12

> 我们为什么没有在`PersonInfo`中使用类内初始化？

因为这里只需要聚合类就够了，所以没有必要在`PersionInfo`中使用类内初始化。



## 练习8.13

> 重写本节的电话号码程序，从一个命名文件而非`cin`读取数据。

```C++
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
struct PersonInfo{
    string name;
    vector<string> phones;
};
int main()
{
    std::ifstream fileInput("../ch08/PersonInfo.txt");
    if (!fileInput)
    {
        std::cout << "Open File Fail !!" << std::endl;
        return EXIT_FAILURE;
    }
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(fileInput, line))
    {
        PersonInfo info;
        record.clear();     //必须要有这个clear函数,复位流的所有标志位
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &phone : p.phones)
            std::cout << phone << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
```

运行结果：

> PS C:\cpp_primer\Debug> .\cpp_primer.exe
> morgan 20015552368 8625550123
> drew 9735550130
> lee 609555012 2015550175 8005550000
> PS C:\\cpp_primer\Debug>



## 练习8.14

> 我们为什么将`entry`和`nums`定义为`const auto&`？

* 它们都是类类型，因此使用引用避免拷贝。
* 在循环当中不会改变它们的值，因此用 const。