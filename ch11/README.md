## 练习11.1

> 描述`map`和`vector`的不同。

`map` 是关联容器， `vector` 是顺序容器。



## 练习11.2

> 分别给出最适合使用`list`、`vector`、`deque`、`map`以及`set`的例子。

* `list`：双向链表，适合频繁插入删除元素的场景。
* `vector`：适合频繁访问元素的场景。
* `deque`：双端队列，适合频繁在头尾插入删除元素的场景。
* `map`：字典。
* `set`：适合有序不重复的元素的场景。



## 练习11.3

> 编写你自己的单词计数程序。

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;
void word_count(map<string, int> m)
{
    string s;
    while (cin >> s){
        m[s] += 1;
    }
    for (const auto& elem : m)
        std::cout << elem.first << " : " << elem.second << endl;
}
int main()
{
    map<string, int> m;
    word_count(m);
    return EXIT_SUCCESS;
}
```

运行结果：

> the about to like no about to the go do about
> ^Z
> about : 3
> do : 1
> go : 1
> like : 1
> no : 1
> the : 2
> to : 2
> 请按任意键继续. . .

## 练习11.4

> 扩展你的程序，忽略大小写和标点。例如，"example."、"example,"和"Example"应该递增相同的计数器。

```C++
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
void word_count(map<string, int> m)
{
    string s;
    while (cin >> s){
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(find_if(s.begin(), s.end(), ispunct),
            s.end());
        m[s] += 1;
    }
    for (const auto& elem : m)
        std::cout << elem.first << " : " << elem.second << endl;
}
int main()
{
    map<string, int> m;
    word_count(m);
    return EXIT_SUCCESS;
}
```

运行结果：

> The about. to like no About to the, go do about
> ^Z
> about : 3
> do : 1
> go : 1
> like : 1
> no : 1
> the : 2
> to : 2
> 请按任意键继续. . .



## 练习11.5

> 解释`map`和`set`的区别。你如何选择使用哪个？

`map` 是键值对，而 `set` 只有键没有值。当我需要存储键值对的时候使用 `map`，而只需要键的时候使用 `set`。



## 练习11.6

> 解释`set`和`list`的区别。你如何选择使用哪个？

`set` 是有序不重复集合，底层实现是红黑树，而 `list` 是无序可重复集合，底层实现是链表。



## 练习11.7

> 定义一个`map`，关键字是家庭的姓，值是一个`vector`，保存家中孩子（们）的名。编写代码，实现添加新的家庭以及向已有家庭中添加新的孩子。

```C++
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    map<string, vector<string>> m;
    string tempString;
    while (getline(cin, tempString))
    {
        istringstream inString(tempString);
        string lastName, firstName;
        inString >> lastName;
        inString >> firstName;
        m[lastName].push_back(firstName);
    }
    cout << "Output Result:" << endl;
    auto iter = m.begin();
    while (iter != m.end())
    {
        for (auto name : iter->second)
        {
            cout << iter->first << " " << name << endl;
        }
        ++iter;
    }

    return EXIT_SUCCESS;
}
```

运行测试：

> aaa bbb
> ccc ddd
> eee fff
> aaa ggg
> ^Z
> Output Result:
> aaa bbb
> aaa ggg
> ccc ddd
> eee fff
> 请按任意键继续. . .



## 练习11.8

> 编写一个程序，在一个`vector`而不是一个`set`中保存不重复的单词。使用`set`的优点是什么？

`set`的优点是集合本身的元素就是不重复。

```C++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> vs = { "aaa", "bbb" };
    string inString;
    while (cin >> inString)
    {
        if (vs.cend() == find(vs.cbegin(), vs.cend(), inString))
        {
            vs.push_back(inString);
        }
    }

    cout << "Output:" << endl;
    for (auto &s : vs)
    {
        cout << s << endl;
    }
    return EXIT_SUCCESS;
}
```

运行测试：

> aaa
> bbb
> fff
> bbb
> sss
> ^Z
> Output:
> aaa
> bbb
> fff
> sss
> 请按任意键继续. . .



## 练习11.9

> 定义一个`map`，将单词与一个行号的`list`关联，`list`中保存的是单词所出现的行号。

```C++
map<string, list<size_t>> m;
```



## 练习11.10

> 可以定义一个`vector<int>::iterator` 到 `int` 的`map`吗？`list<int>::iterator` 到 `int` 的`map`呢？对于两种情况，如果不能，解释为什么。

可以定义 `vector<int>::iterator` 到 `int` 的`map`，但是不能定义 `list<int>::iterator` 到 `int` 的`map`。因为`map`的键必须实现 `<` 操作，`list` 的迭代器不支持比较运算。



## 练习11.11

> 不使用`decltype` 重新定义 `bookstore`。

```C++
using Less = bool (*)(Sales_data const&, Sales_data const&);
std::multiset<Sales_data, Less> bookstore(less);
```



## 练习11.12

> 编写程序，读入`string`和`int`的序列，将每个`string`和`int`存入一个`pair` 中，`pair`保存在一个`vector`中。

```C++
#include <vector>
#include <string>
#include <iostream>
int main()
{
    std::vector<std::pair<std::string, int>> vec;
    std::string str;
    int i;
    while (std::cin >> str >> i)
        vec.push_back(std::pair<std::string, int>(str, i));

    for (const auto &p : vec)
        std::cout << p.first << ":" << p.second << std::endl;

    return EXIT_SUCCESS;
}
```

运行测试：

> aaa 2
> bbb 3
> ccc 1
> ^Z
> aaa:2
> bbb:3
> ccc:1
> 请按任意键继续. . .



## 练习11.13

> 在上一题的程序中，至少有三种创建`pair`的方法。编写此程序的三个版本，分别采用不同的方法创建`pair`。解释你认为哪种形式最易于编写和理解，为什么？

```C++
vec.push_back(std::make_pair(str, i));
vec.push_back({ str, i });
vec.push_back(std::pair<string, int>(str, i)); 
```

使用花括号的初始化器最易于理解和编写。



## 练习11.14

> 扩展你在11.2.1节练习中编写的孩子姓达到名的`map`，添加一个`pair`的`vector`，保存孩子的名和生日。

```C++
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    map<string, vector<pair<string,string>>> m;
    string tempString;
    while (getline(cin, tempString))
    {
        istringstream inString(tempString);
        string lastName, firstName, birthday;
        inString >> lastName;
        inString >> firstName;
        inString >> birthday;
        m[lastName].push_back({ firstName, birthday });
    }
    cout << "Output Result:" << endl;
    auto iter = m.begin();
    while (iter != m.end())
    {
        for (auto name : iter->second)
        {
            cout << iter->first << " "
                << name.first << " "
                << name.second << endl;
        }
        ++iter;
    }

    return EXIT_SUCCESS;
}
```

运行测试：

> aaa bbb 20200101
> ccc ddd 20200501
> ^Z
> Output Result:
> aaa bbb 20200101
> ccc ddd 20200501
> 请按任意键继续. . .