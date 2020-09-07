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

