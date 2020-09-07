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