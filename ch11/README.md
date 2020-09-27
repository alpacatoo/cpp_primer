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



## 练习11.15

> 对一个`int`到`vector<int>的map`，其`mapped_type`、`key_type`和 `value_type`分别是什么？

* `mapped_type` : `vector<int>`
* `key_type` : `int`
* `value_type` : `std::pair<const int,vector >`



## 练习11.16

> 使用一个`map`迭代器编写一个表达式，将一个值赋予一个元素。

```C++
std::map<int, string>::iterator it = m.begin();
it->second = "hello";
```



## 练习11.17

> 假定`c`是一个`string`的`multiset`，`v` 是一个`string` 的`vector`，解释下面的调用。指出每个调用是否合法：
>
> ```C++
> copy(v.begin(), v.end(), inserter(c, c.end()));
> copy(v.begin(), v.end(), back_inserter(c));
> copy(c.begin(), c.end(), inserter(v, v.end()));
> copy(c.begin(), c.end(), back_inserter(v));
> ```

第二个调用不合法，因为 `multiset` 没有 `push_back` 方法。其他调用都合法。



## 练习11.18

> 写出第382页循环中`map_it` 的类型，不要使用`auto` 或 `decltype`。

```C++
map<string, size_t>::const_iterator map_it = word_count.cbegin();
```



## 练习11.19

> 定义一个变量，通过对11.2.2节中的名为 `bookstore` 的`multiset` 调用`begin()`来初始化这个变量。写出变量的类型，不要使用`auto` 或 `decltype`。

```C++
using compareType = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
std::multiset<Sales_data, compareType> bookstore(compareIsbn);
std::multiset<Sales_data, compareType>::iterator c_it = bookstore.begin();
```



## 练习11.20

> 重写11.1节练习的单词计数程序，使用`insert`代替下标操作。你认为哪个程序更容易编写和阅读？解释原因。

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
        auto result = m.insert({ s, 1 });
        if (!result.second)			//second是插入是否成功，已有key不会成功
            ++result.first->second;	//first是指向元素的迭代器的，将元素的second累加
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

运行测试：

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

使用`insert`更容易阅读和编写。`insert`有返回值，可以明确的体现出插入操作的结果。



## 练习11.21

> 假定`word_count`是一个`string`到`size_t`的`map`，`word`是一个`string`，解释下面循环的作用：
>
> ```C++
> while (cin >> word)
> 	++word_count.insert({word, 0}).first->second;
> ```

插入{word, 0}这个pair，如果word已经存在，则累加；若不存在，则插入的数值为0，insert返回该pair的迭代器，累加后数值从0变为1。



## 练习11.22

> 给定一个map<string, vector<int>>，对此容器的插入一个元素的insert版本，写出其参数类型和返回类型。

```C++
std::pair<std::string, std::vector<int>>    // 参数类型
std::pair<std::map<std::string, std::vector<int>>::iterator, bool> // 返回类型
```



## 练习11.23

> 11.2.1节练习中的map 以孩子的姓为关键字，保存他们的名的vector，用multimap 重写此map。

```C++
#include <iostream>
#include <string>
#include <map>
using std::string;
int main(void)
{
    std::multimap<string, string> names;
    for (string first, last; std::cin >> first >> last; names.emplace(last, first));
    for (auto const& family : names)
        std::cout << family.second << " " << family.first << std::endl;
    return EXIT_SUCCESS;
}
```

运行结果：

> aaa bbb
> ccc ddd
> eee fff
> aaa ggg
> ^Z
> aaa bbb
> ccc ddd
> eee fff
> aaa ggg
> 请按任意键继续. . .



## 练习11.24

> 下面的程序完成什么功能？
>
> ```C++
> map<int, int> m;
> m[0] = 1;
> ```

添加一个元素到 map 中，如果该键存在，则重新赋值。



## 练习11.25

> 对比下面的程序与上一题程序
>
> ```C++
> vector<int> v;
> v[0] = 1;
> ```

未定义行为，vector 的下标越界访问。



## 练习11.26

> 可以用什么类型来对一个map进行下标操作？下标运算符返回的类型是什么？请给出一个具体例子——即，定义一个map，然后写出一个可以用来对map进行下标操作的类型以及下标运算符将会返会的类型。

```C++
std::map<int, std::string> m = { { 1,"ss" },{ 2,"sz" } };
using KeyType = std::map<int, std::string>::key_type;	
using ReturnType = std::map<int, std::string>::mapped_type;
```



## 练习11.27

> 对于什么问题你会使用count来解决？什么时候你又会选择find呢？

对于允许重复关键字的容器，应该用 count ; 对于不允许重复关键字的容器，应该用 find 。



## 练习11.28

> 对一个string到int的vector的map，定义并初始化一个变量来保存在其上调用find所返回的结果。

```C++
map<string, vector<int>> m;
map<string, vector<int>>::iterator it = m.find("key");
```



## 练习11.29

> 如果给定的关键字不在容器中，upper_bound、lower_bound 和 equal_range 分别会返回什么？

如果给定的关键字不在容器中，则 lower_bound和 upper_bound 会返回相等的迭代器，指向一个不影响排序的关键字插入位置。而equal_range 会返回一个 pair，pair 中的两个迭代器都指向关键字可以插入的位置。



## 练习11.30

> 对于本节最后一个程序中的输出表达式，解释运算对象pos.first->second的含义。

pos 是一个 pair，pos.first 是一个迭代器，指向匹配关键字的元素，该元素是一个 pair，访问该元素的第二个成员。



## 练习11.31

> 编写程序，定义一个作者及其作品的multimap。使用find在multimap中查找一个元素并用erase删除它。确保你的程序在元素不在map 中时也能正常运行。

```C++
#include <iostream>
#include <map>
#include <string>
using std::string;
using std::multimap;
int main()
{
    std::multimap<string, string> authors{
        { "aaa", "bbb" },
        { "ccc", "ddd" },
        { "ddd", "eee" },
        { "ccc", "fff" } };

    string author = "ccc";
    string book = "fff";

    auto found = authors.find(author);  //指向第一个关键字为author的迭代器
    auto num = authors.count(author);   //返回关键字为author的元素个数

    while (num)
    {
        if (found->second == book)
        {
            authors.erase(found);
            break;
        }
        ++found;
        --num;
    }

    for (const auto &author : authors)
        std::cout << author.first << " " << author.second << std::endl;

    return EXIT_SUCCESS;
}
```

运行结果：

> aaa bbb
> ccc ddd
> ddd eee
> 请按任意键继续. . .



## 练习11.32

> 使用上一题定义的multimap 编写一个程序，按字典序打印作者列表和他们的作品。

```C++
#include <iostream>
#include <map>
#include <set>
#include <string>
using std::string;
int main()
{
    std::multimap<string, string> authors{
        { "aaa", "bbb" },
        { "ddd", "ddd" },
        { "ccc", "eee" },
        { "ccc", "fff" } };

    std::map<string, std::multiset<string>> order_authors;
    for (const auto &author : authors)
        order_authors[author.first].insert(author.second);
    for (const auto &author : order_authors)
    {
        std::cout << author.first << ": ";
        for (const auto &book : author.second)
            std::cout << book << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
```

运行结果：

> aaa: bbb
> ccc: eee fff
> ddd: ddd
> 请按任意键继续. . .



## 练习11.33

> 实现你自己版本的单词转换程序。

```C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;  //存放转换规则
    string key;                     //存放要转换的单词
    string value;                   //替换后的内容
    //读取第一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)       //检查是否有转换规则
            trans_map[key] = value.substr(1);   //跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}
const string & transform(const string &s, const map<string, string> &m)
{
    //实际完成转换工作；此部分是程序的核心部分
    auto map_it = m.find(s);
    //如果单词在转换规则中map中
    if (map_it != m.cend())
        return map_it->second;  //使用替换短语
    else
        return s;               //否则返回原string
}
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);        //保存转换规则
    string text;                                //保存输入的第一行
    while (getline(input, text))                //读取一行输入
    {
        istringstream stream(text);
        string word;
        bool firstword = true;                  //控制是否打印空格
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " ";                    //在单词间打印一个空格
            cout << transform(word, trans_map); //打印输出
        }
        cout << endl;                           //完成一行转换
    }
}
int main()
{
    ifstream ifs_rules("../ch11/transform_rules.txt");
    ifstream ifs_txt("../ch11/for_transform.txt");

    word_transform(ifs_rules, ifs_txt);

    return EXIT_SUCCESS;
}
```

运行结果：

> PS C:\cpp_primer\Debug> .\cpp_primer.exe
> whrer are you
> why dont you send me a picture
> okay? thanks! later
> PS C:\cpp_primer\Debug>



## 练习11.34

> 如果你将transform 函数中的find替换为下标运算符，会发生什么情况？

如果使用下标运算符，当关键字未在容器中时，会往容器中添加一个新元素。



## 练习11.35

> 在buildMap中，如果进行如下改写，会有什么效果？
>
> ```C++
> trans_map[key] = value.substr(1);
> //改为
> trans_map.insert({key, value.substr(1)});
> ```

当一个转换规则的关键字多次出现的时候，使用下标运算符会保留最后一次添加的规则，而用insert则保留第一次添加的规则。



## 练习11.36

> 我们的程序并没检查输入文件的合法性。特别是，它假定转换规则文件中的规则都是有意义的。如果文件中的某一行包含一个关键字、一个空格，然后就结束了，会发生什么？预测程序的行为并进行验证，再与你的程序进行比较。

如果关键字没有对应的规则，那么程序会抛出一个 `runtime_error`。



## 练习11.37

> 一个无序容器与其有序版本相比有何优势？有序版本有何优势？

无序容器拥有更好的性能，有序容器使得元素始终有序。



## 练习11.38

> 用 unordered_map 重写单词计数程序和单词转换程序。

```C++
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;
unordered_map<string, string> buildMap(ifstream &map_file)
{
    unordered_map<string, string> trans_map;  //存放转换规则
    string key;                     //存放要转换的单词
    string value;                   //替换后的内容
    //读取第一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)       //检查是否有转换规则
            trans_map[key] = value.substr(1);   //跳过前导空格
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}
const string & transform(const string &s, const unordered_map<string, string> &m)
{
    //实际完成转换工作；此部分是程序的核心部分
    auto map_it = m.find(s);
    //如果单词在转换规则中map中
    if (map_it != m.cend())
        return map_it->second;  //使用替换短语
    else
        return s;               //否则返回原string
}
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);        //保存转换规则
    string text;                                //保存输入的第一行
    while (getline(input, text))                //读取一行输入
    {
        istringstream stream(text);
        string word;
        bool firstword = true;                  //控制是否打印空格
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " ";                    //在单词间打印一个空格
            cout << transform(word, trans_map); //打印输出
        }
        cout << endl;                           //完成一行转换
    }
}
int main()
{
    ifstream ifs_rules("../ch11/transform_rules.txt");
    ifstream ifs_txt("../ch11/for_transform.txt");

    word_transform(ifs_rules, ifs_txt);

    return EXIT_SUCCESS;
}
```

运行结果：

> PS C:\cpp_primer\Debug> .\cpp_primer.exe
> whrer are you
> why dont you send me a picture
> okay? thanks! later
> PS C:\cpp_primer\Debug>