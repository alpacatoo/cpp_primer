# 第9章 顺序容器



## 练习9.1

> 对于下面的程序任务，`vector`、`deque`和`list`哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
>  (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
>  (b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
>  (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

(a) `list` ，因为需要频繁的插入操作。
(b) `deque` ，总是在头尾进行插入、删除操作。
(c) `vector` ，不需要进行插入删除操作。



## 练习9.2

> 定义一个`list`对象，其元素类型是`int`的`deque`。

```C++
std::list<std::deque<int> > obj;
```



## 练习9.3

> 构成迭代器范围的迭代器有何限制？

它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。

我们可以通过反复递增`begin`来到达`end`。换句话说，`end` 不在`begin`之前。



## 练习9.4

> 编写函数，接受一对指向`vector<int>`的迭代器和一个`int`值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```C++
#include <iostream>
#include <vector>
using std::vector;
bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int ref)
{
    while (begin != end)
    {
        if (*begin == ref)
        {
            return true;
        }
        ++begin;
    }
    return false;
}

int main()
{
    int inputInt;
    vector<int> nums{3,4,1,6,5};
    while (std::cin >> inputInt)
    {
        std::cout << (find(nums.cbegin(), nums.cend(), inputInt) ? "True" : "False")
            << std::endl;
    }
        
    return EXIT_SUCCESS;
}
```

运行结果：

>1
>True
>2
>False
>3
>True
>4
>True
>5
>True
>6
>True
>7
>False
>^Z
>请按任意键继续. . .



## 练习9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```C++
#include <vector>
#include <iostream>
using std::vector;
vector<int>::const_iterator find(vector<int>::const_iterator begin,
    vector<int>::const_iterator end,
    int ref)
{
    while (begin != end)
    {
        if (*begin == ref)
            return begin;
        ++begin;
    }
    return end;
}

int main()
{
    int inputInt;
    vector<int> nums{ 3, 4, 1, 6, 5 };
    while (std::cin >> inputInt)
    {
        if (find(nums.cbegin(), nums.cend(), inputInt) == nums.cend())
            std::cout << "There are no this number." << std::endl;
        else
            std::cout << "Find number: " << inputInt << std::endl;
    }

    return EXIT_SUCCESS;
}
```

> 1
> Find number: 1
> 2
> There are no this number.
> 3
> Find number: 3
> ^Z
> 请按任意键继续. . .



## 练习9.6

> 下面的程序有何错误？你应该如何修改它？
>
> ```c++
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(),
> 					iter2 = lst1.end();
> while (iter1 < iter2) /* ... */
> ```

修改成如下：

```C++
while (iter1 != iter2)
```



## 练习9.7

> 为了索引`int`的`vector`中的元素，应该使用什么类型？

```C++
vector<int>::size_type
```



## 练习9.8

> 为了读取`string`的`list`中的元素，应该使用什么类型？如果写入`list`，又应该使用什么类型？

```C++
list<string>::const_iterator // 读
list<string>::iterator // 写
```



## 练习9.9

> `begin`和`cbegin`两个函数有什么不同？

`begin` 返回的是普通迭代器，只有在对`const`对象调用时返回常量迭代器；`cbegin` 返回的是常量迭代器。



## 练习9.10

> 下面4个对象分别是什么类型？
>
> ```C++
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin(), it2 = v2.begin();
> auto it3 = v1.cbegin(), it4 = v2.cbegin();
> ```

`it1`是`vector<int>::iterator`；剩余的变量是`vector<int>::interator`类型



## 练习9.11

> 对6种创建和初始化`vector`对象的方法，每一种都给出一个实例。解释每个`vector`包含什么值。

```C++
vector<int> vec;    // 0
vector<int> vec(10);    // 10个0
vector<int> vec(10, 1);  // 10个1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // 拷贝 other_vec 的元素
vector<int> vec(other_vec.begin(), other_vec.end()); // 拷贝 other_vec 的元素
```



## 练习9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

接受一个容器创建其拷贝的构造函数，必须**容器类型和元素类型**都相同。

接受两个迭代器创建拷贝的构造函数，只需要**元素的类型能够相互转换**，容器类型和元素类型可以不同。



## 练习9.13

> 如何从一个`list<int>`初始化一个`vector<double>`？从一个`vector<int>`又该如何创建？编写代码验证你的答案。

```C++
list<int> ilst(5, 4);
vector<int> ivc(5, 5);
vector<double> dvc(ilst.begin(), ilst.end());
vector<double> dvc2(ivc.begin(), ivc.end());
```



## 练习9.14

> 编写程序，将一个`list`中的`char *`指针元素赋值给一个`vector`中的`string`。

```C++
std::list<const char*> l{ "hello", "world" };
std::vector<std::string> v;
v.assign(l.cbegin(), l.cend());
```



## 练习9.15

> 编写程序，判定两个`vector<int>`是否相等。

```C++
#include <vector>
#include <iostream>
using std::vector;
int main()
{
    vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> v2 = { 1, 2, 3, 4 };
    std::cout << (v1 == v2 ? "True" : "False") << std::endl;
    std::cout << (v1 > v2 ? "True" : "False") << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> False
> True
> 请按任意键继续. . .



## 练习9.16

> 重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。

```C++
#include <vector>
#include <iostream>
#include <list>
using std::list;
using std::vector;
int main()
{
    list<int> v1 = { 1, 2, 3, 4, 5, 6 };
    vector<int> v2 = { 1, 2, 3, 4 };
    std::cout << (vector<int>(v1.begin(),v1.end()) == v2 ? "True" : "False") << std::endl;
    std::cout << (vector<int>(v1.begin(), v1.end()) > v2 ? "True" : "False") << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> False
> True
> 请按任意键继续. . .



## 练习9.17

> 假定`c1`和`c2`是两个容器，下面的比较操作有何限制？
>
> ```C++
> if (c1 < c2)
> ```

（1）`c1`和`c2`必须是相同类型的容器并且保存相同类型的元素;

（2）元素支持关系运算符



## 练习9.18

> 编写程序，从标准输入读取`string`序列，存入一个`deque`中。编写一个循环，用迭代器打印`deque`中的元素。

```c++
#include <deque>
#include <string>
#include <iostream>
using std::deque;
using std::string;
int main()
{
    deque<string> inDequeString;
    string inString;
    while (std::cin >> inString)
        inDequeString.push_back(inString);
    for (auto s : inDequeString)
        std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> hello word!!
> how are you?
> Thank you.
> ^Z
> hello
> word!!
> how
> are
> you?
> Thank
> you.
> 请按任意键继续. . .



## 练习9.19

> 重写上一题的程序，用`list`替代`deque`。列出程序要做出哪些改变。

将`deque`定义的变量修改为`list`定义

```C++
#include <list>
#include <string>
#include <iostream>
using std::list;
using std::string;
int main()
{
    list<string> inDequeString;
    string inString;
    while (std::cin >> inString)
        inDequeString.push_back(inString);
    for (auto s : inDequeString)
        std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> hello world!!
> how are you?
> Thank you.
> ^Z
> hello
> world!!
> how
> are
> you?
> Thank
> you.
> 请按任意键继续. . .



## 练习9.20

> 编写程序，从一个`list<int>`拷贝元素到两个`deque`中。值为偶数的所有元素都拷贝到一个`deque`中，而奇数值元素都拷贝到另一个`deque`中。

```C++
#include <iostream>
#include <deque>
#include <list>
int main()
{
    std::list<int> myList{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::deque<int> odd, even;
    for (auto i : myList)
        (i & 0x1 ? odd : even).push_back(i);

    for (auto i : odd) 
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : even)
        std::cout << i << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
```

运行结果：

> 1 3 5 7 9
> 2 4 6 8 10
> 请按任意键继续. . .



## 练习9.21

> 如果我们将第308页中使用`insert`返回值将元素添加到`list`中的循环程序改写为将元素插入到`vector`中，分析循环将如何工作。

```C++
auto iter = v.begin();
while(std::cin >> word)
	iter = v.insert(iter, word);
```



## 练习9.22

> 假定`iv`是一个`int`的`vector`，下面的程序存在什么错误？你将如何修改？
>
> ```C++
> vector<int>::iterator iter = iv.begin(),
> 					  mid = iv.begin() + iv.size() / 2;
> while (iter != mid)
> 	if (*iter == some_val)
> 		iv.insert(iter, 2 * some_val);
> ```

循环不会结束；迭代器可能会失效

```C++
vector<int>::iterator iter = iv.begin();
int mid = iv.size() / 2;
while ((iter - iv.begin()) < mid)
{
    if (*iter == some_val)
    {
        iter = iv.insert(iter, 2 * some_val);
        ++mid;
        ++iter;
    }
    ++iter;
}
```



## 练习9.23

> 在本节第一个程序中，若`c.size()` 为1，则`val`、`val2`、`val3`和`val4`的值会是什么？

都会是同一个值（容器中仅有的那个）。



## 练习9.24

> 编写程序，分别使用`at`、下标运算符、`front` 和 `begin` 提取一个`vector`中的第一个元素。在一个空`vector`上测试你的程序。

```c++
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v;
    std::cout << v.at(0);       // terminating with uncaught exception of type std::out_of_range
    std::cout << v[0];          // Segmentation fault: 11
    std::cout << v.front();     // Segmentation fault: 11
    std::cout << *v.begin();    // Segmentation fault: 11
    return 0;
}
```



## 练习9.25

> 对于第312页中删除一个范围内的元素的程序，如果 `elem1` 与 `elem2` 相等会发生什么？如果 `elem2` 是尾后迭代器，或者 `elem1` 和 `elem2` 皆为尾后迭代器，又会发生什么？

* 如果 `elem1` 和 `elem2` 相等，那么不会发生任何操作。
* 如果`elem2` 是尾后迭代器，那么删除从 `elem1` 到最后的元素。
* 如果两者皆为尾后迭代器，也什么都不会发生。



## 练习9.26

> 使用下面代码定义的`ia`，将`ia`拷贝到一个`vector`和一个`list`中。是用单迭代器版本的`erase`从`list`中删除奇数元素，从`vector`中删除偶数元素。````
>
> ```C++
> int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
> ```

```C++
#include <vector>
#include <list>
#include <iostream>
using std::vector;
using std::list;
int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> v(std::begin(ia), std::end(ia));
    list<int> l(v.begin(), v.end());

    auto v_iter = v.begin();
    while (v_iter != v.end())
    {
        if (*v_iter & 0x1)
            ++v_iter;
        else
            v_iter = v.erase(v_iter);
    }
    auto l_iter = l.begin();
    while (l_iter != l.end())
    {
        if (*l_iter & 0x1)
            l_iter = l.erase(l_iter);
        else
            ++l_iter;
    }

    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    for (auto i : l)
        std::cout << i << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
```

运行结果：

> 1 1 3 5 13 21 55 89
> 0 2 8
> 请按任意键继续. . .



## 练习9.27

> 编写程序，查找并删除`forward_list<int>`中的奇数元素。

```C++
#include <forward_list>
#include <iostream>
using std::forward_list;
int main()
{
    forward_list<int> fl{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = fl.before_begin();
    auto curr = fl.begin();
    while (curr != fl.end())
    {
        if (*curr & 0x1)
        {
            prev = curr;
            ++curr;
        }
        else
            curr = fl.erase_after(prev);
        
    }
    for (auto i : fl)
        std::cout << i << " ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 1 3 5 7 9
> 请按任意键继续. . .



## 练习9.28

> 编写函数，接受一个`forward_list<string>`和两个`string`共三个参数。函数应在链表中查找第一个`string`，并将第二个`string`插入到紧接着第一个`string`之后的位置。若第一个`string`未在链表中，则将第二个`string`插入到链表末尾。

```C++
#include <forward_list>
#include <string>
#include <iostream>
using std::forward_list;
using std::string;
forward_list<string>::iterator myInsert(forward_list<string> &list, string s, string i)
{
    auto prev = list.before_begin();
    auto curr = list.begin();
    while (curr != list.end())
    {
        if (*curr == s)
            return list.insert_after(curr, i);
        prev = curr;
        ++curr;
    }
    return list.insert_after(prev, i);
}
void myPrint(forward_list<string>  &list)
{
    for (auto &s:list)
        std::cout << s << ",";
    std::cout << std::endl;
}
int main()
{
    forward_list<string> list1{"hello", "like", "OK"};
    forward_list<string> list2 = list1;
    string search = "like";
    string in = "world";
    myInsert(list1, search, in);
    myPrint(list1);
    search = "bye";
    myInsert(list2, search, in);
    myPrint(list2);
    return EXIT_SUCCESS;
}
```

运行结果：

> hello,like,world,OK,
> hello,like,OK,world,
> 请按任意键继续. . .



## 练习9.29

> 假定`vec`包含25个元素，那么`vec.resize(100)`会做什么？如果接下来调用`vec.resize(10)`会做什么？	

`vec.resize(100)`会将多余的75个位置，设置为值为0的元素添加到`vec`的末尾

`vec.resize(10)`从`vec`的末尾删除90个元素



## 练习9.30

> 接受单个参数的`resize`版本对元素类型有什么限制（如果有的话）？

元素类型必须提供一个默认构造函数。



## 练习9.31

> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于`list`或`forward_list`。为什么？修改程序，使之也能用于这些类型。

```C++
iter += 2;
```

因为复合赋值语句只能用于`string`、`vector`、`deque`、`array`，所以要改为：

```C++
    std::list<int> list = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto iter_list = list.begin();
    while (iter_list != list.end())
    {
        if (*iter_list & 0x1)
        {
            iter_list = list.insert(iter_list, *iter_list);
            ++iter_list;		//自增两次
            ++iter_list;
        }
        else
        {
            iter_list = list.erase(iter_list);
        }
    }
```

如果是`forward_list`的话，要增加一个首先迭代器`prev`：

```C++
	std::forward_list<int> forwardlist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = forwardlist.before_begin();
    auto curr = forwardlist.begin();
    while (curr != forwardlist.end())
    {
        if (*curr & 0x1)
        {
            curr = forwardlist.insert_after(curr, *curr);
            prev = curr;
            ++curr;
        }
        else
            curr = forwardlist.erase_after(prev);
    }
```



## 练习9.32

> 在第316页的程序中，向下面语句这样调用`insert`是否合法？如果不合法，为什么？
>
> ```C++
> iter = vi.insert(iter, *iter++);
> ```

不合法。因为参数的求值顺序是未定义的。



## 练习9.33

> 在本节最后一个例子中，如果不将`insert`的结果赋予`begin`，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

`begin`将会失效。



## 练习9.34

> 假定`vi`是一个保存`int`的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>
> ```C++
> iter = vi.begin();
> while (iter != vi.end())
> 	if (*iter % 2)
> 		iter = vi.insert(iter, *iter);
> 	++iter;
> ```

循环永远不会结束。`++iter;`语句不在while语句中。



## 练习9.35

> 解释一个`vector`的`capacity`和`size`有何区别。

`capacity`的值表明，在不重新分配内存空间的情况下，容器可以保存多少元素

而`size`的值是指容器已经保存的元素的数量



## 练习9.36

> 一个容器的`capacity`可能小于它的`size`吗？

不可能。



## 练习9.37

> 为什么`list`或`array`没有`capacity`成员函数？

因为`list`是链表，而`array`不允许改变容器大小。



## 练习9.38

> 编写程序，探究在你的标准实现中，`vector`是如何增长的。

```C++
#include <iostream>
#include <string>
#include <vector>
int main()
{
    std::vector<int> v;
    for (int i = 0; i < 50; i++)
    {
        std::cout << "capacity: " << v.capacity() << "  size: " << v.size() << std::endl;
        v.push_back(i);
    }
    return 0;
}
```

运行结果：

> capacity: 0  size: 0
> capacity: 1  size: 1
> capacity: 2  size: 2
> capacity: 3  size: 3
> capacity: 4  size: 4
> capacity: 6  size: 5
> capacity: 6  size: 6
> capacity: 9  size: 7
> capacity: 9  size: 8
> capacity: 9  size: 9
> capacity: 13  size: 10
> capacity: 13  size: 11
> capacity: 13  size: 12
> capacity: 13  size: 13
> capacity: 19  size: 14
> capacity: 19  size: 15
> capacity: 19  size: 16
> capacity: 19  size: 17
> capacity: 19  size: 18
> capacity: 19  size: 19
> capacity: 28  size: 20
> capacity: 28  size: 21
> capacity: 28  size: 22
> capacity: 28  size: 23
> capacity: 28  size: 24
> capacity: 28  size: 25
> capacity: 28  size: 26
> capacity: 28  size: 27
> capacity: 28  size: 28
> capacity: 42  size: 29
> capacity: 42  size: 30
> capacity: 42  size: 31
> capacity: 42  size: 32
> capacity: 42  size: 33
> capacity: 42  size: 34
> capacity: 42  size: 35
> capacity: 42  size: 36
> capacity: 42  size: 37
> capacity: 42  size: 38
> capacity: 42  size: 39
> capacity: 42  size: 40
> capacity: 42  size: 41
> capacity: 42  size: 42
> capacity: 63  size: 43
> capacity: 63  size: 44
> capacity: 63  size: 45
> capacity: 63  size: 46
> capacity: 63  size: 47
> capacity: 63  size: 48
> capacity: 63  size: 49
> 请按任意键继续. . .



## 练习9.39

> 解释下面程序片段做了什么：
>
> ```C++
> vector<string> svec;
> svec.reserve(1024);
> string word;
> while (cin >> word)
> 	svec.push_back(word);
> svec.resize(svec.size() + svec.size() / 2);
> ```

定义一个`vector`，为它分配1024个元素的空间。然后通过一个循环从标准输入中读取字符串并添加到`vector`当中。循环结束后，改变`vector`的容器大小（元素数量）为原来的1.5倍，使用元素的默认初始化值填充。如果容器的大小超过1024，`vector`也会重新分配空间以容纳新增的元素。



## 练习9.40

> 如果上一题的程序读入了256个词，在`resize`之后容器的`capacity`可能是多少？如果读入了512个、1000个、或1048个呢？

如果读入了256个词，`capacity` 仍然是 1024

如果读入了512个词，`capacity` 仍然是 1024

如果读入了1000个词，`capacity` 仍然是 1024

如果读入了1048个词，`capacity` 取决于具体实现。



## 练习9.41

> 编写程序，从一个`vector<char>`初始化一个`string`。

```C++
vector<char> v{'h', 'e', 'l', 'l', '0'};
string s(v.begin(), v.end());
```



## 练习9.42

> 假定你希望每次读取一个字符存入一个`string`中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

使用 `reserve(100)` 函数预先分配100个元素的空间。



## 练习9.43

> 编写一个函数，接受三个`string`参数是`s`、`oldVal` 和`newVal`。使用迭代器及`insert`和`erase`函数将`s`中所有`oldVal`替换为`newVal`。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

```C++
#include <iostream>
#include <string>
using std::string;

void replace_with(string &s, string oldval, string newval)
{
    auto curr = s.begin();
    while (curr != (s.end()-oldval.size()))
    {
        if (oldval == string(curr, curr+oldval.size()))
        {
            curr = s.erase(curr, curr + oldval.size());
            curr = s.insert(curr, newval.begin(), newval.end());
            curr += newval.size();
        }
        else
            ++curr;
    }
}

int main()
{
    string s{ "hello how thru world thu like love haha tho end." };
    std::cout << s << std::endl;
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> hello how thru world thu like love haha tho end.
> hello how through world thu like love haha though end.
> 请按任意键继续. . .



## 练习9.44

> 重写上一题的函数，这次使用一个下标和`replace`。

```C++
#include <iostream>
#include <string>
using std::string;

void replace_with(string &s, string oldval, string newval)
{
    size_t curr = 0;
    while (curr < (s.size()-oldval.size()))
    {
        if (oldval == s.substr(curr, oldval.size()))
        {
            s = s.replace(curr,oldval.size(),newval);
            curr += newval.size();
        }
        else
            ++curr;
    }
}

int main()
{
    string s{ "hello how thru world thu like love haha tho end." };
    std::cout << s << std::endl;
    replace_with(s, "tho", "though");
    replace_with(s, "thru", "through");
    replace_with(s, "love", "le");
    std::cout << s << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> hello how thru world thu like love haha tho end.
> hello how through world thu like le haha though end.
> 请按任意键继续. . .



## 练习9.45

> 编写一个函数，接受一个表示名字的`string`参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及`insert`和`append`函数将前缀和后缀添加到给定的名字中，将生成的新`string`返回。

```C++
#include <iostream>
#include <string>
using std::string;
void add_pre_suffix(string &name, string pre, string suffix)
{
    name.insert(name.begin(), pre.begin(), pre.end());
    name.append(suffix);
}
int main()
{
    string name("alpacatoo");
    add_pre_suffix(name, "Mr.", " Jr.");
    std::cout << name << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> Mr.alpacatoo Jr.
> 请按任意键继续. . .



## 练习9.46

> 重写上一题的函数，这次使用位置和长度来管理`string`，并只使用`insert`。

```C++
#include <iostream>
#include <string>
using std::string;
void add_pre_suffix(string &name, string pre, string suffix)
{
    name.insert(0, pre);
    name.insert(name.size(), suffix);
}
int main()
{
    string name("alpacatoo");
    add_pre_suffix(name, "Mr.", " Jr.");
    std::cout << name << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> Mr.alpacatoo Jr.
> 请按任意键继续. . .



## 练习9.47

> 编写程序，首先查找`string`"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用`find_first_of`，第二个要使用`find_first_not_of`。

```C++
#include <iostream>
#include <string>
using std::string;
int main()
{
    string numbers("0123456789");
    string s("ab2c3d7R4E6");
    std::cout << "find_first_of:" << std::endl;
    for (int pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
        std::cout << s[pos] << ", ";
    std::cout << std::endl;
    std::cout << "find_first_not_of:" << std::endl;
    for (int pos = 0; (pos = s.find_first_not_of(numbers, pos)) != string::npos; ++pos)
        std::cout << s[pos] << ", ";
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> find_first_of:
> 2, 3, 7, 4, 6,
> find_first_not_of:
> a, b, c, d, R, E,
> 请按任意键继续. . .



## 练习9.48

> 假定`name`和`numbers`的定义如325页所示，`numbers.find(name)`返回什么？

返回 `string::npos`



## 练习9.49

> 如果一个字母延伸到中线之上，如d或f，则称其有上出头部分（`ascender`）。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（`descender`）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

```C++
#include <string>
#include <iostream>
#include <fstream>
using std::string;
int main()
{
    std::ifstream ifs("../ch09/find.txt");
    if (!ifs)   return EXIT_FAILURE;
    string s,longest;
    while (ifs >> s)
    {
        if (string::npos == s.find_first_not_of("aceimnorsuvwxz"))
        {
            longest = longest.size() < s.size() ? s : longest;
        }
    }
    std::cout << longest << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> PS C:\cpp_primer\Debug> .\cpp_primer.exe
> aceimnorsuvwxz
> PS C:\\cpp_primer\Debug>



## 练习9.50

> 编写程序处理一个`vector<string>`，其元素都表示整型值。计算`vector`中所有元素之和。修改程序，使之计算表示浮点值的`string`之和。

```C++
#include <string>
#include <iostream>
#include <vector>
int sum_int(std::vector<std::string> & v)
{
    int sum = 0;
    for (auto i : v)
        sum += std::stoi(i);
    return sum;
}
double sum_double(std::vector<std::string> &v)
{
    double sum = 0.0;
    for (auto d : v)
    {
        sum += std::stod(d);
    }
    return sum;
}
int main()
{
    std::vector<std::string> v{"1", "2.5", "3.2"};
    std::cout << sum_int(v) << std::endl;
    std::cout << sum_double(v) << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> 6
> 6.7
> 请按任意键继续. . .



## 练习9.51

> 设计一个类，它有三个`unsigned`成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的`string`参数。你的构造函数应该能处理不同的数据格式，如January 1,1900、1/1/1990、Jan 1 1900 等。

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class myData
{
private:
    unsigned day = 1, month = 1, year = 1970;
public:
    myData(const string &s)
    {
        if (s.find("/") != string::npos)
        {
            // 1/1/1900
            auto first = s.find_first_of("/");
            auto second = s.find_last_of("/");
            month = stoi(s.substr(0, first));
            day = stoi(s.substr(first + 1, second - first - 1));
            year = stoi(s.substr(second + 1));
        }
        else
        {
            // January 1, 1900 or Jan 1, 1900 or Jan 1 1900
            vector<string> months{"Jan","Feb", "Mar", "Apr", "May","June", 
                "July","Aug", "Sep", "Oct", "Nov", "Dec"};
            auto curr = months.begin();
            while (curr != months.end())
            {
                if (string::npos != s.find(*curr))    
                    break;  
                ++curr;
            }
            if (curr != months.end())
            {
                month = curr - months.begin() + 1;
                auto first = s.find_first_of(" ,");
                auto second = s.find_last_of(" ,");
                day = stoi(s.substr(first + 1, second - first - 1));
                year = stoi(s.substr(second + 1));
            }
        }
    }
    void print_data(const char * s)
    {
        cout << s
            << "Year: " << year << ", "
            << "Month: " << month << ", "
            << "Day: " << day << endl;
    }
};

int main()
{
    myData format1("4/30/1982: ");
    format1.print_data("4/12/1982 : ");
    myData format2("February 27,2001");
    format2.print_data("February 27,2001: ");
    myData format3("Sep 22 2010");
    format3.print_data("Sep 22 2010: ");
    myData format4("July 7, 2014");
    format4.print_data("July 15, 2014 : ");
    return EXIT_SUCCESS;
}
```

运行结果：

> 4/12/1982 : Year: 1982, Month: 4, Day: 30
> February 27,2001: Year: 2001, Month: 2, Day: 27
> Sep 22 2010: Year: 2010, Month: 9, Day: 22
> July 15, 2014 : Year: 2014, Month: 7, Day: 7
> 请按任意键继续. . .



## 练习9.52

> 使用`stack`处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从`stack`中`pop`对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）`push`到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。

```C++
#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string expr{"11+2*5+(14*2+3)*6"};
    vector<string> v;
    //split
    string::size_type front_pos = 0;
    string::size_type back_pos = expr.find_first_of("-+*/()");
    while (string::npos != back_pos)
    {
        if (front_pos != back_pos)  // number
            v.push_back(expr.substr(front_pos, back_pos - front_pos));
        v.push_back(expr.substr(back_pos, 1));  // operator
        front_pos = back_pos + 1;
        back_pos = expr.find_first_of("-+*/()", front_pos);
    }
    v.push_back(expr.substr(front_pos));
    //打印分段
    std::cout << "split v: " << endl;
    for (auto s : v)
        std::cout << s << endl;

    // back format
    stack<string> stk;
    vector<string> v_back;
    for (auto s : v)
    {
        if (s.size() > 1 || string::npos == s.find_first_of("-+*/()"))
        {   //操作数
            v_back.push_back(s);
        }
        else if (s == ")")
        {
            while (stk.top() != "(")
            {
                
                v_back.push_back(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else
        {   // "-+*/("
            while (!stk.empty())
            {
                if ((s == "-" || s == "+") &&
                    (stk.top() == "*" || stk.top() == "/"))
                {   //当前字符优先级低于栈顶元素，出栈
                    v_back.push_back(stk.top());
                    stk.pop();
                }
                else
                {
                    break;
                }
            }
            //出栈后，将字符压入
            stk.push(s);
        }
    }
    while (!stk.empty())
    {
        v_back.push_back(stk.top());
        stk.pop();
    }
    //打印后缀
    std::cout << "back v: " << endl;
    for (auto s : v_back)
        std::cout << s << endl;
    // calculate
    stack<double> stk_sum;
    for (auto s : v_back)
    {
        if (s.size() > 1 || string::npos == s.find_first_of("-+*/()"))
        {   //操作数
            stk_sum.push(stod(s));
        }
        else
        {
            auto op1 = stk_sum.top();
            stk_sum.pop();
            auto op2 = stk_sum.top();
            stk_sum.pop();
            switch (s[0])
            {
            case '-': stk_sum.push(op2 - op1); break;
            case '+': stk_sum.push(op2 + op1); break;
            case '*': stk_sum.push(op2 * op1); break;
            case '/': stk_sum.push(op2 / op1); break;
            default: break;
            }
        }
    }
    std::cout << "Result: " << stk_sum.top() << endl;
 
}
```

运行结果：

> split v:
> 11
> +
> 2
> *
> 5
> +
> (
> 14
> *
> 2
> +
> 3
> )
> *
> 6
> back v:
> 11
> 2
> 5
> *
> 14
> 2
> *
> 3
> +
> 6
> *
> +
> +
> Result: 207
> 请按任意键继续. . .