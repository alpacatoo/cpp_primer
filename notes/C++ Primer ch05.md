# 第5章 语句

## 简单语句

- **表达式语句（expression statement）**：一个表达式末尾加上逗号，例如表达式为`ival+5`，则表达式语句为`ival+5;`
- 表达式语句的作用是**执行表达式**并**丢弃掉求值结果**
- **空语句（null statement）**：只包含一个单独的分号的表达式语句
- 表达式多余的逗号被视为**空语句**，多余的逗号不是总是无害，例如在`if`和`while`的条件之后
- **复合语句（compound statement）**指花括号包围的语句和声明语句，也被称为**块**



## 语句作用域

- 可以在`if`，`switch`，`while`，`for`语句内定义变量，变量在语句内可见



## 条件语句

- C++的两种条件控制流：`if`语句和`switch`语句；

### if语句

- `if`语句的形式

```C++
if (condition)
    statement
```

- `if else`语句

```C++
if (condition)
    statement
else
    statement2
```

- 每个statement都 可以是复合语句块，且可嵌套if语句
- **悬垂else**：else与离他最近的尚未匹配的if匹配

### switch语句

- `switch`语句计算一个整型表达式的值；条件是整数
- 语句形式

```C++
switch (condition)
{
    case num_1:
        statement;
        break;
    case num_2:
    case num_3:
        statement;
   		break;
    default:
        statement;
        break;
}
```

- 从匹配的`case`情况处开始执行，直到遇到`break`或到右花括号结束
- 在语句内定义变量，需要定义在使用变量的`case`语句块下



## 迭代语句

### while语句

- 语法形式

```C++
while (condition)
    statement
```

- 适合于不确定迭代次数的情形

### 传统for语句

- 语法形式

```C++
for (init-statemen; condition; expression)
    statement
```

- `init-statement`可以是声明语句、表达式语句或者**空语句**；只能有一个声明语句，每个变量的基础类型必须相同
- `init-statemen`、`condition`、`expression`任何一个可以省略，甚至全部；**分号必须保留**来表明存在省略
- 省略`condition`的效果于条件写了`true`

### 范围for循环

- 语法形式

```C++
for (declaration : expression)
    statement
```

- `expression`表示的必须是一个**序列**，拥有能返回**迭代器的begin和end成员**
- `declaration`定义变量类型是**序列**元素能转换的，建议用`auto`自动推断；需要的序列中元素**写操作**，变量必须声明为**引用类型**
- 转换为传统for语句如下例子；由于修改序列会使得end函数失效，所以不能在范围for循环中添加或删除元素

```C++
for (auto &r : v)
    r *=2;
//等价于
for (auto beg = v.begin(), end = v.end(); beg != end; ++beg)
{
    auto &r = *beg;
    r *=2
}
```

### do while语句

- 至少执行一次循环，语法形式

```C++
do
    statement
while(condition);
```

- 不能在条件部分定义变量，因为要先执行循环体



## 跳转语句

- 四种跳转语句：`break`，`continue`，`goto`，`return`

### break语句

- `break`语句负责**终止离它最近**的`while`，`do while`，`for`或`switch`语句

### continue语句

- `continue`语句**终止最近循环中当前迭代**并立即开始下一次迭代

### goto语句

- 无条件跳转到**同一函数内**的另一条语句
- 语法形式：`goto lable`



## try语句块和异常处理

- 异常处理包括
  - `throw`表达式：`throw`**引发**了异常
  - `try`语句块：处理异常代码；以关键字`try`开始并以一个或多个`catch`子句结束
  - 异常类：用于`throw`和相关`catch`子句之间传递异常的具体信息

### throw表达式

- 表达式类型就是抛出的异常类型，例如`throw runtime_error("Format error!")`

### try语句块

- 语法形式

```C++
try{
    program-statements
} catch (exception-declaration) {
    handler-statements
} catch (exception-declaration) {
    handler-statements
}
```

- `catch`子句由关键字`catch`，异常声明，块组成
- 函数**逐层回退**查找匹配的`catch`子句；如果最终没有**任何匹配**的`catch`子句，则程序转到**terminate**的标准库函数

### 标准异常

- 定义在4个头文件：
  - `exception`头文件：定义通用异常类`exception`
  - `stdexcept`头文件：定义几种通用的异常类
    - `exception`：最常见的问题
    - `runtime_error`：只有在运行时才能检测出的问题
    - `range_error`：运行时错误，生成的结果超出了有意义的值域范围
    - `overflow_error`：运行时错误，计算上溢
    - `underflow_error`：运行时错误，计算下溢
    - `logic_error`：程序逻辑错误
    - `domain_error`：逻辑错误，参数对应的结果值不存在
    - `invalid_argument`：逻辑错误，无效参数
    - `length_error`：逻辑错误，试图创建一个超出该类型最大长度的对象
    - `out_of_range`：逻辑错误，使用一个超出有效范围的值
  - `new`头文件：定义`bad_alloc`异常类型
  - `type_info`头文件：定义`bad_cast`异常类型
- 标准库异常类只定义几种运算，包括创建或拷贝异常类型的对象
- `exception`、`bad_alloc`、`bad_cast`只能**默认初始化**
- 其余异常类型可以通过`string`对象或C风格字符串初始化
- 异常类型定义了`what`成员函数，返回C风格字符串，即`cosnt char*`类型的异常信息。