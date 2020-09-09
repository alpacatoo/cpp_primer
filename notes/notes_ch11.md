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
- pair是一个用来上特定类型的模板
- pair的数据成员是public的，两个成员分别命名为first和second
- map的元素是pair
- 构造函数初始化
  - 默认构造函数值初始化：`pair<stirng, string> anon;`
  - 提供值进行值初始化：`pair<string, string> author{"James", "Joyce"};`
- 花括号包围的初始化器返回pair类型：`return {num_1, num_2};`
- 创建pair对象的**函数**：`make_pair`，例如，`make_pair(num_1, num_2);`

