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

