## 练习3.1

> 使用恰当的using声明重做1.1.1节（第11页）和2.6.2节（第67页）的练习。

练习1.9
```C++
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int sum = 0, count = 50;
    while (count <= 100)
    {
        sum += count;
        count++;
    }
    cout << sum << endl;
}
```

练习1.10

```C++
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    int count = 10;
    while (count >= 0)
    {
        cout << count << endl;
        count--;
    }
}
```

练习1.11

```C++
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    int count = 10;
    int hi = 0, lo = 0, temp = 0;
    cout << "Input low number:" << endl;
    cin >> lo;
    cout << "Input high number:" << endl;
    cin >> hi;

    while (lo <= hi)
    {
        cout << lo << endl;
        lo++;
    }
}
```



## 练习3.2

> 编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。

读入一行

```C++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    while (getline(std::cin, s))
    {
        std::cout << s << std::endl;
    }
    return 0;
}
```

读入一个词

```C++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string word;
    while (std::cin >> word)
    {
        std::cout << word << std::endl;
    }
    return 0;
}
```



## 练习3.3

> 请说明string类的输入运算符和geline函数分别是如恶化处理空白字符的。

- 类似 cin >> s 的读取，string对象会忽略开头的空白并从第一个真正的字符开始，直到遇见下一空白为止。
- 类似 getline(is, s) 的读取，string对象会从输入流中读取字符，直到遇见换行符为止



## 练习3.4

> 编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

比较大小：

```C++
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1 == str2)
            cout << "The tow strings is same!" << endl;
        else
            cout << "The larger string is " << ((str1 > str2) ? str1 : str2) << endl;
    }
    return 0;
}
```

比较长度

```C++
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (str1.size() == str2.size())
            cout << "The tow strings have same length!" << endl;
        else
            cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2) << endl;
    }
    return 0;
}
```



## 练习3.5

> 编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分隔开来。

不分隔开

```C++
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string result, s;
    while (cin >> s)
        result += s;
    cout << result << endl;
    return 0;
}
```

分隔开

```C++
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string result, s;
    while (cin >> s)
        result += s + " ";
    cout << result << endl;
    return 0;
}
```



## 练习3.6

> 编写一段程序，使用范围for语句将字符串照顾内的所欲字符用X代替

```C++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    std::cin >> s;
    for (auto &c : s)
        c = 'X';
    std::cout << s << std::endl;
    return 0;
}
```



## 练习3.7

> 就上一题完成的程序而言，如果将循环控制的变量设置为char将发生什么？先估计一下结果，然后实际编程进行验证。

如果设置为char，那么原来的字符串不会发生改变。

```C++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string s;
    std::cin >> s;
    for (char c : s)
        c = 'X';
    std::cout << s << std::endl;
    return 0;
}
```



## 练习3.8

> 分别用while循环和传统for循环重写第一题的程序，你觉得哪种形式更好呢？为什么？

范围for语句更好，不直接操作索引，更简洁。



## 练习3.9

> 下面的程序有何作用？它合法吗？如果不合法？为什么？
>
> ```C++
> string s;
> cout << s[0] << endl;
> ```

不合法，因为s没有初始化，是一个空字符串，不能通过下标访问。



## 练习3.10

> 编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。

```C++
#include <iostream>
#include <string>
#include <cctype>
using std::string;
using std::cout;
using std::endl;
int main()
{
    string s = "I'm don't sleep! go ahead.";
    string result;
    for (auto c : s)
        if (!ispunct(c))
            result += c;
    cout << result << endl;
    return 0;
}
```



## 练习3.11

> 下面的范围for语句合法吗？如果合法，c的类型是什么？
>
> ```C++
> const string s = "Keep out!";
> for(auto &c : s){ /* ... */ }
> ```

要根据for循环中的代码来看是否合法，c是string 对象中字符的引用，s是常量。因此如果for循环中的代码重新给c赋值就会非法，如果不改变c的值，那么合法。



## 练习3.12

> 下列vector对象的定义有不正确的吗？如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。

```C++
vector<vector<int>> ivec;         // 在C++11当中合法
vector<string> svec = ivec;       // 不合法，类型不一样
vector<string> svec(10, "null");  // 合法
```



## 练习3.13

> 下列的vector对象各包含多少个元素？这些元素的值分别是多少？

```C++
vector<int> v1;         // size:0,  no values.
vector<int> v2(10);     // size:10, value:0
vector<int> v3(10, 42); // size:10, value:42
vector<int> v4{ 10 };     // size:1,  value:10
vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
vector<string> v6{ 10 };  // size:10, value:""
vector<string> v7{ 10, "hi" };  // size:10, value:"hi"
```



## 练习3.14

> 编写一段程序，用cin读入一组整数并把它们存入一个vector对。

```C++
#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
    {
        v.push_back(i);
    }
    for (auto c : v)
        std::cout << c << std::endl;
    return 0;
}
```



## 练习3.15

> 改写上题程序，不过这次读入的是字符串。

```C++
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
int main()
{
    vector<string> v;
    string s;
    while (std::cin >> s)
    {
        v.push_back(s);
    }
    for (auto s : v)
        std::cout << s << std::endl;
    return 0;
}
```



## 练习3.16

> 编写一段程序，把练习3.13中vector对象的容量和具体内容输出出来

```C++
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    cout << "v1 size :" << v1.size() << endl;
    cout << "v2 size :" << v2.size() << endl;
    cout << "v3 size :" << v3.size() << endl;
    cout << "v4 size :" << v4.size() << endl;
    cout << "v5 size :" << v5.size() << endl;
    cout << "v6 size :" << v6.size() << endl;
    cout << "v7 size :" << v7.size() << endl;

    cout << "v1 content: ";
    for (auto i : v1)
        cout << i << " , ";
    cout << endl;

    cout << "v2 content: ";
    for (auto i : v2)
        cout << i << " , ";
    cout << endl;

    cout << "v3 content: ";
    for (auto i : v3)
        cout << i << " , ";
    cout << endl;

    cout << "v4 content: ";
    for (auto i : v4)
        cout << i << " , ";
    cout << endl;

    cout << "v5 content: ";
    for (auto i : v5)
        cout << i << " , ";
    cout << endl;

    cout << "v6 content: ";
    for (auto i : v6)
        cout << i << " , ";
    cout << endl;

    cout << "v7 content: ";
    for (auto i : v7)
        cout << i << " , ";
    cout << endl;

    return 0;
}
```



## 练习3.17

> 从cin读入一组词并把它们存入一个vector对象，然后设法把所有词都改为大写形式。输出改变后的结果，每个词占一行。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
int main()
{
    vector<string> origin;
    string s;
    while (std::cin >> s)
        origin.push_back(s);
    for (auto &s : origin)
        for (auto &c : s)
            c = toupper(c);

    for (auto s:origin)
        std::cout << s << std::endl;

    return 0;
}
```



## 练习3.18

> 下面的程序合法吗？如果不合法，你准备如何修改？
>
> ```C++
> vector<int> ivec;
> ivec[0] = 42;
> ```

不合法。应修改为：

```C++
ivec.push_back(42);
```



## 练习3.19

> 如果想定义一个含有10个元素的vector对象，所有元素的值都是42，请例举三种不同的实现方法，哪种方式更好呢？

```C++
vector<int> v1(10, 42);
vector<int> v2{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };
vector<int> v3;
for (int i = 0; i < 10; ++i)
	v3.push_back(42);
```

第一种方式最好。



## 练习3.20

> 读入一组整数并把他们存入一个vector对象，将每对相邻整数的和输出出来。改写你的程序，这次要求先输出第一个和最后一个元素的和，接着输入第二个和倒数第二个元素的和，以此类推。

```C++
#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (vector<int>::size_type pos = 0; pos < v.size() - 1; ++pos)
        std::cout << v[pos] + v[pos + 1] << std::endl;
    int beginPos = 0;
    int endPos = v.size() - 1;
    while (beginPos <= endPos)
    {
        std::cout << v[beginPos] + v[endPos] << std::endl;
        beginPos++;
        endPos--;
    }
    return 0;
}
```



## 练习3.21

> 请使用迭代器重做3.3.3节（第94页）的第一个练习。

```C++
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

void my_print(const vector<int> &v)
{
    cout << "Size: " << v.size() << " Context: [";
    for (auto begin = v.begin(); begin != v.end(); begin++)
        cout << *begin << (begin != v.end() - 1 ? "," : "");
    cout << "]" << endl;
}

void my_print(const vector<string> &v)
{
    cout << "Size: " << v.size() << " Context: [";
    for (auto begin = v.begin(); begin != v.end(); begin++)
        cout << *begin << (begin != v.end() - 1 ? "," : "");
    cout << "]" << endl;
}

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    my_print(v1);
    my_print(v2);
    my_print(v3);
    my_print(v4);
    my_print(v5);
    my_print(v6);
    my_print(v7);

    return 0;
}
```



## 练习3.22

> 修改之前那个输出text第一段的程序，首先把text的第一段全部改成大写形式，然后输出它。

```C++
#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    vector<string> text;
    text.push_back("aaaaaaaaaa aaaaaaaaa aaaaaa");
    text.push_back("");
    text.push_back("bbbbbbbbbbbbbb bbbbbbbbbbb bbbbbbbbbbbbb");

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        for (auto &c : *it)
            if (isalpha(c)) c = toupper(c);
    for (auto it : text)
        cout << it << endl;
    return 0;
}
```



## 练习3.23

> 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。输出vector对象的内容，检验程序是否正确。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using std::string;
using std::vector;
int main()
{
    vector<string> origin;
    string s;
    while (std::cin >> s)
        origin.push_back(s);
    for (auto &s : origin)
        for (auto &c : s)
            c = toupper(c);

    for (auto s:origin)
        std::cout << s << std::endl;

    return 0;
}
```



## 练习3.24

> 请使用迭代器重做3.3.3节（第94页）的最后一个练习。

```C++
#include <iostream>
#include <vector>
using std::vector;
int main()
{
    vector<int> v;
    int i;
    while (std::cin >> i)
        v.push_back(i);
    for (auto it = v.begin(); it != v.end() - 1; it++)
        std::cout << *it + *(it + 1) << std::endl;
    auto beginIt = v.begin();
    auto endIt = v.end() - 1;
    while (beginIt <= endIt)
    {
        std::cout << *beginIt + *endIt << std::endl;
        beginIt++;
        endIt--;
    }
    return 0;
}
```



## 练习3.25

> 3.3.3节（第93页）划分分数段的程序是使用下标运算符实现的，请利用迭代器改写该程序实现完全相同的功能。

```C++
#include <vector>
#include <iostream>
using std::vector;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++*(scores.begin() + grade / 10);
    }

    for (auto s : scores)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}
```



## 练习3.26

> 在100页的二分搜索程序中，为什么用的是 mid = beg + (end - beg) / 2, 而非 mid = (beg + end) / 2 ; ?

因为迭代器支持的运算只有 - ，而没有 + 。end - beg 意思是相距若干个元素，将之除以2然后与beg相加，表示将beg移动到一半的位置。



## 练习3.27

> 假设txt_size 是一个无参函数，它的返回值是int。请回答下列哪个定义是非法的，为什么？

```C++
unsigned buf_size = 1024;
(a) int ia[buf_size];				//非法。维度必须是常量表达式
(b) int ia[4 * 7 - 14];				//合法。
(c) int ia[txt_size()];				//非法，txt_size()函数返回的是int类型。
(d) char st[11] = "fundamental";	//非法，字符串的长度是12
```



## 练习3.28

> 下列数组中元素的值是什么？
>
> ```C++
> string sa[10];
> int ia[10];
> int main() {
> 	string sa2[10];
> 	int ia2[10];
> }
> ```

数组的元素会被默认初始化。sa 的元素值全部为空字符串，ia 的元素值全部为0。sa2 的元素值全部为空字符串，ia2 的元素值全部未定义。



## 练习3.29

> 相比于vector 来说，数组有哪些缺点，请例举一些。

- 数组的大小是确定的。
- 不能随意增加元素
- 不允许拷贝和赋值



## 练习3.30

> 指出下面代码中的索引错误。
>
> ```C++
> constexpr size_t array_size = 10;
> int ia[array_size];
> for (size_t ix = 1; ix <= array_size; ++ix)
> 	ia[ix] = ix;
> ```

当 ix 增长到 10 的时候，ia[ix] 的下标越界。



## 练习3.31

> 编写一段程序，定义一个含有10个int的数组，令每个元素的值就是其下标值。

```C++
#include <vector>
int main()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	return 0;
}
```



## 练习3.32

> 将上一题刚刚创建的数组拷贝给另一数组。利用vector重写程序，实现类似的功能。

```C++
#include <iostream>
#include <vector>
using std::cout; using std::endl; using std::vector;

int main()
{
    // array
    int arr[10];
    for (int i = 0; i < 10; ++i) arr[i] = i;
    int arr2[10];
    for (int i = 0; i < 10; ++i) arr2[i] = arr[i];

    // vector
    vector<int> v(10);
    for (int i = 0; i != 10; ++i) v[i] = arr[i];
    vector<int> v2(v);
    for (auto i : v2) cout << i << " ";
    cout << endl;

    return 0;
}
```



## 练习3.33

> 对于104页的程序来说，如果不初始化scores将会发生什么？

数组中所有元素的值将会未定义。



## 练习3.34

> 假定p1 和 p2 都指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
>
> ```C++
> p1 += p2 - p1;
> ```

将 p1 移动到 p2 的位置。任何情况下都合法。



## 练习3.35

> 编写一段程序，利用指针将数组中的元素置为0。

```C++
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    const int size = 10;
    int arr[size];
    for (auto ptr = arr; ptr != arr + size; ++ptr) *ptr = 0;
    for (auto i : arr) cout << i << " ";
    cout << endl;
    return 0;
}
```



## 练习3.36

> 编写一段程序，比较两个数组是否相等。再写一段程序，比较两个vector对象是否相等。

```C++
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
bool compare(int* const pb1, int* const pe1, int* const pb2, int* const pe2)
{
    if ((pe1 - pb1) != (pe2 - pb2))
        return false;
    else
    {
        for (int* i = pb1, *j = pb2; (i != pe1) && (j != pe2); ++i, ++j)
            if (*i != *j) return false;
    }

    return true;
}
int main()
{
    int arr1[3] = { 0, 1, 2 };
    int arr2[3] = { 0, 2, 4 };

    if (compare(begin(arr1), end(arr1), begin(arr2), end(arr2)))
        cout << "The two arrays are equal." << endl;
    else
        cout << "The two arrays are not equal." << endl;

    vector<int> vec1 = { 0, 1, 2 };
    vector<int> vec2 = { 0, 1, 2 };

    if (vec1 == vec2)
        cout << "The two vectors are equal." << endl;
    else
        cout << "The two vectors are not equal." << endl;

    return 0;
}
```



## 练习3.37

> 下面的程序是何含义，程序的输出结果是什么？
>
> ```C++
> const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
> const char *cp = ca;
> while (*cp) {
>     cout << *cp << endl;
>     ++cp;
> }
> ```

会将ca 字符数组中的元素打印出来。但是因为没有空字符的存在，程序不会退出循环。



## 练习3.38

> 在本节中我们提到，将两个指针相加不但是非法的，而且也没有什么意义。请问为什么两个指针相加没有意义？

将两个指针相减可以表示两个指针(在同一数组中)相距的距离，将指针加上一个整数也可以表示移动这个指针到某一位置。但是两个指针相加并没有逻辑上的意义，因此两个指针不能相加。



## 练习3.39

> 编写一段程序，比较两个string对象。再编写一段程序，比较两个C风格字符串的内容。

```C++
#include <iostream>
#include <string>
#include <cstring>
using std::cout; using std::endl; using std::string;

int main()
{
    string s1("aaaaaaaaaa"), s2("bbbbbbbbbb");
    if (s1 == s2)
        cout << "same string." << endl;
    else if (s1 > s2)
        cout << "aaaaaaaaaa > bbbbbbbbbb" << endl;
    else
        cout << "aaaaaaaaaa < bbbbbbbbbb" << endl;

    cout << "=========" << endl;

    const char* cs1 = "aaaaaaaaaa";
    const char* cs2 = "bbbbbbbbbb";
    auto result = strcmp(cs1, cs2);
    if (result == 0)
        cout << "same string." << endl;
    else if (result < 0)
        cout << "aaaaaaaaaa < bbbbbbbbbb" << endl;
    else
        cout << "aaaaaaaaaa > bbbbbbbbbb" << endl;

    return 0;
}
```



## 练习3.40

> 编写一段程序，定义两个字符数组并用字符串字面值初始化它们；接着再定义一个字符数组存放前面两个数组连接后的结果。使用strcpy和strcat把前两个数组的内容拷贝到第三个数组当中。

```C++
#include <iostream>
#include <cstring>

const char cstr1[] = "Hello";
const char cstr2[] = "world!";

int main()
{
    char cstr3[100];

    strcpy_s(cstr3, cstr1);
    strcat_s(cstr3, " ");
    strcat_s(cstr3, cstr2);

    std::cout << cstr3 << std::endl;
}
```



## 练习3.41

> 编写一段程序，用整型数组初始化一个vector对象。

```C++
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    vector<int> v(begin(arr), end(arr));

    for (auto i : v) cout << i << " ";
    cout << endl;

    return 0;
}
```



## 练习3.42

> 编写一段程序，将含有整数元素的vector对象拷贝给一个整型数组。

```C++
#include <iostream>
#include <cstring>

const char cstr1[] = "Hello";
const char cstr2[] = "world!";

int main()
{
    char cstr3[100];

    strcpy_s(cstr3, cstr1);
    strcat_s(cstr3, " ");
    strcat_s(cstr3, cstr2);

    std::cout << cstr3 << std::endl;
}
```



## 练习3.43

>编写3个不同版本的程序，令其均能输出ia的元素。版本1使用范围for语句管理迭代过程；版本2和版本3都使用普通for语句，其中版本2要求使用下标运算符，版本3要求使用指针。此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto关键字和decltype关键字。

```C++
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int arr[3][4] =
    {
        { 0, 1, 2, 3 },
        { 4, 5, 6, 7 },
        { 8, 9, 10, 11 }
    };

    // range for
    for (const int(&row)[4] : arr)
        for (int col : row) cout << col << " ";

    cout << endl;

    // for loop
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j) cout << arr[i][j] << " ";

    cout << endl;

    // using pointers.
    for (int(*row)[4] = arr; row != arr + 3; ++row)
        for (int *col = *row; col != *row + 4; ++col) cout << *col << " ";

    cout << endl;

    return 0;
}
```



## 练习3.44

> 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。

```C++
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

    using int_array = int[4];

    for (int_array& p : ia)
        for (int q : p)
            cout << q << " ";
    cout << endl;

    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 4; ++j)
            cout << ia[i][j] << " ";
    cout << endl;

    for (int_array* p = ia; p != ia + 3; ++p)
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << " ";
    cout << endl;

    return 0;
}
```



## 练习3.45

> 再一次改写程序，这次使用auto关键字。

```C++
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	int ia[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

	for (auto& p : ia)
		for (auto q : p)
			cout << q << " ";
	cout << endl;

	for (auto i = 0; i != 3; ++i)
		for (auto j = 0; j != 4; ++j)
			cout << ia[i][j] << " ";
	cout << endl;

	for (auto p = ia; p != ia + 3; ++p)
		for (auto q = *p; q != *p + 4; ++q)
			cout << *q << " ";
	cout << endl;

	return 0;
}
```

