# 第一章 开始

## 程序结构
　　每个C++的程序包含一个或多个函数，其中必须有一个main函数，称为主函数。每个函数至少由返回类型、函数名、形参列表、函数体构成，其结构如下所示：
```C++
return_type function_name(parameter list)
{
    function_body
}
```
　　形参列表被包括在一对括号中，且可以为空；函数体是由左花括号开始，以右花括号结束的语句块。对于主函数而言，返回类型为内置类型int型，参数列表为空。返回值0表示成功，返回值非0表示失败。

## 输入输出（IO）
　　C++语言本身不提供输入输出语句，通过标准库实现IO机制。**iostream**库是一个比较常用的IO库，包含**istream**和**ostream**基础类型。

　　标准库定义了4个IO对象：（1）标准输入cin；（2）标准输出cout；（3）标准错误cerr；（4）一般性信息clog

　　输入和输出程序实例如下所示：
```C++
std::cout << "hello world!" << std::endl;
std::cin >> input;
```
　　程序中：（1）包含了两个**表达式**；一个表达式产生一个计算结果，由一个或多个运算对象和运算符组成。（2）`<<`是一个输出运算符，在标准输出中输出信息；（3）`>>`是一个输入运算符，从标准输入中读入数据；（4）`"hello world!"`是一个字符串字面值常量；（5）`endl`是一种操纵符，用于刷新缓冲区；（6）`std`是一个命名空间名，表明cout、endl、cin在该命名空间定义的；（7）`::`是一个作用域运算符，指出将使用std命名空间中的对象。

## 注释
　　C++中分为单行注释和多行注释这两种注释。

　　单号注释以`//`开始，以换行符结束。

　　多行注释以`/*`开始，以`*/`符号结束；可以包含除结束符号`*/`以外的所有符号。**注意：** 多行注释不可嵌套使用。

## while语句
　　while语句的形式为：
```C++
while (condition)
    statement
```
　　当condition为真时执行statement，直到condition为假不再执行。statement可以是一个表达式，也可以是一个语句块。

## for语句
　　for语句的形式为：
```C++
for (init_statement; condition; expression)
    statement
```
其中，`statment`是花括号包围的语句块或表达式；for语句的执行循序为：
1. 执行init_statement
2. 判断condition；若为真，执行statement，并执行expression；若为假，退出循环
3. 重复第2个步骤

## if语句
　　if语句具有多种形式，其形式如下所示
```C++
# 形式1
if (condition)
    statement;          //condition为真时执行

# 形式2
if (condition)
    statement_true;     //condition为真时执行
else
    statement_false;    //condition为假时执行

# 形式3
if (condition_1)
    statement_1;            //condition_1为真时执行
else if (condition_2)
    statement_2;            //condition_2为真时执行
...
else if (condition_n)
    statement_n;            //condition_n为真时执行
else
    statement_all_false;    //所有条件为假时执行
```

## 文件结束符EOF
　　Windows输入：Ctrl+Z

　　Mac OS输入；Ctrl+D


## 文件重定向
　　程序addItem从infile输入数据，outfile输出数据。
```shell
$ addItem <infile >outfile
```