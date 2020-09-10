# 第11章 关联容器

- 两个主要关联容器：map，set
- 容器默认关键字不可重复，重复的关联容器名字中加`multi`
- 不保持容器的顺序使用`unorder`开头
- 有序的map（不管是否重复关键字）在**map**头文件；有序的sset（不管是否重复关键字）在**set**头文件
- 无序容器定义在**unordered_map**和**unordered_set**头文件中

## 11.1 使用关联容器

- map容器
  - map类型通常被称为关联数组；定义时指定关键字和值的类型；例如，`map<string, size_t> word_count;`
  - 访问元素：`word_count[key_name]`；通过关键字直接访问元素，**赋值时，若关键字不存在，则创建该键值对**
  - 从map中提取元素时，会得到一个`pair`类型的对象，用`first`成员保存关键字，用`second`成员保存对应值
- set容器
  - 定义：`set<key_type>`，例如，`set<strng>`
  - 可以进行列表初始化，例如，`set<string> exclude = {"The", "But"}`
  - 使用成员函数find查找一个单词是否存在



## 11.2 关联容器概述

- 不支持书匈奴容器的位置相关的操作
- 关联容器的迭代器是双向的

### 定义关联容器

- 定义map时，必须芝麻关键字类型又指明值类型
- 定义set时，只需要指明关键字类型
- 关联容器具有默认构造函数，会创建一个指定类型的空容器；或另一个同类型容器的拷贝；或一直值范围初始化
- 每个键值对用花括号包围：`{key, value}`
- map和set的关键字必须唯一；multimap和multiset的关键字表可以不唯一

### 关键字类型要求

- 有序关联容器关键字类型必须定义元素比较的方法；默认使用`<`进行比较
- 有序关联容器的关键字类型
  - 必须定义一个严格弱序
  - 比较函数需要满足的基本性质
    - 不能同时小于等于对方
    - 比较具有传导性
    - 均不小于等于对方，则等价
- 定义multiset时候，若关键字没有<操作符，则必须提供比较操作类型，这是一种寒素指针类型：`multiset<Sales_data, decltype(compareIsbn)*>

### pair类型

- 定义在头文件`utility`中
- `pair`是一个用来上特定类型的模板
- `pair`的数据成员是public的，两个成员分别命名为`first`和`second`
- `map`的元素是`pair`
- 构造函数初始化
  - 默认构造函数值初始化：`pair<stirng, string> anon;`
  - 提供值进行值初始化：`pair<string, string> author{"James", "Joyce"};`
- 花括号包围的初始化器返回pair类型：`return {num_1, num_2};`
- 创建pair对象的**函数**：`make_pair`，例如，`make_pair(num_1, num_2);`
- 关系运算符：先比较`first`成员，在`first`成员相等情况下，再比较`second`成员
- 相等运算符：`first`成员和`second`成员都相等的情况下，才算相等



## 11.3 关联容器操作

- 容器关键字和值的类型

  - `key_type`：容器类型的**关键字**类型

  - `mapped_type`：每个关键字关联的类型；只适用于`map`

  - `value_type`：

    - `set`情况下，`value_type`等于`key_type`
    - `map`情况下，`value_type`等于`pair<const key_type, mapped_typed>`
    - 由于不能改变一个元素的关键字，因此`pair`的关键字部分是`const`
- 使用作用域运算符来提取一个类型的成员，例如，`map<string, int>::key_type>`

### 11.3.1 关联容器迭代器

- 解引用一个关联容器迭代器时，我们会得到一个类型为容器的`value_type`的值的引用
- `set`的迭代器是`const`的；虽然其定义了`iterator`和`const_iterator`类型，但都只运行制度访问`set`的元素
- 遍历关联容器
  - 获得首个迭代器，判断是否为尾后迭代器进行遍历
  - 遍历的迭代器按照**关键字升序遍历元素**
- 关联容器只可用于只读取元素的算法；几乎不用泛型算法
- 关联容器使用算法，将它当作一个源序列，要么当作一个目的位置





