# IO库

- istream（输入流）类型，提供输入操作
- ostream（输出流）类型，提供输出操作
- cin，一个istream对象，从标准输入读取数据
- cout，一个ostream对象，向标准输出写入数据
- cerr，一个ostream对象，通常用于输出程序错误信息，写入到标准错误
- `>>`运算符，从一个istream对象读取输入数据
- `<<`运算符，向一个ostream对象写入输出数据
- getline函数，给定一个istream读取一行数据，存入一个给定的string对象中



## IO类

| 头文件     | 类型（有w前缀是对wchar_t类型数据的操作）                     |
| ---------- | ------------------------------------------------------------ |
| `iostream` | `istream`, `wistream`：从流读取数据<br />`ostream`,  `wostream`：向流写入数据<br />`iostream`, `wiostream`：读写流 |
| `fstream`  | `ifstream`, `wifstream`：从文件读取数据<br />`ofstream`,  `wofstream`：向文件写入数据<br />`iofstream`, `wiofstream`：读写文件 |
| `sstream`  | `istringstream`, `wistringstream`：从string读取数据<br />`ostringstream`,  `wostringstream`：向string写入数据<br />`iostringstream`, `wiostringstream`：读写string |

- 它们之间通过基础机制实现，通常可以将拍摄类当作基类对象使用

### IO对象无拷贝或赋值

- IO操作函数只能通过引用方式传递和返回流；
- IO对象不能是`const`的，因为IO对象会改变状态

### 条件状态

| 状态（`strm`是一种IO类型，`s`是流对象） | 解释                                            |
| --------------------------------------- | ----------------------------------------------- |
| `strm::iostate`                         | 提供表达条件状态的完整功能                      |
| `strm::badbit`                          | 指出流已经崩溃                                  |
| `strm::failbit`                         | 指出一个IO操作失败                              |
| `strm::eofbit`                          | 指出流到达文件结束                              |
| `strm::goodbit`                         | 指出流未处于错误状态，此值保证为0               |
| `s.eof()`                               | 流`s`的`eofbit`置位返回`true`                   |
| `s.fail()`                              | 流`s`的`failbit`或`badbit`置位返回`true`        |
| `s.bad()`                               | 流`s`的`badbit`置位返回`true`                   |
| `s.good()`                              | 流`s`处于有效状态返回true                       |
| `s.clear()`                             | 条件状态复位，流状态设置位有效，返回`void`      |
| `s.clear(flags)`                        | 根据`flags`标志位，对应条件状态复位，返回`void` |
| `s.setstate(flags)`                     | 据`flags`标志位，对应条件状态设置，返回`void`   |
| `s.rdstate()`                           | 返回当前条件状态                                |

- badbit表示系统级错误，不能恢复
- failbit表示可恢复错误，例如读错类型等
- 到达文件末尾，eofbit和failbit都会置位
- badbit置位时，failbit也会置位
- 使用good和fail是确定流的总体状态的正确方法，eofbit和badbit只能指示特定错误

### 管理输出缓冲

- 每个输出流管理一个输出缓冲区；缓冲机制使得操作系统可以见程序多个输出组合成单一的**系统级写操作**
- 缓冲刷新的条件：
  - 程序正常结束
  - 缓冲区满
  - 使用操作符，如endl，显示刷新缓冲区
  - 使用操纵符unitbuf设置流的内部状态来清空缓冲区；cerr默认色湖之unitbuf
  - 流A关联到流B，流A的读或写使得流B的缓冲区被刷新
- flush操纵符：刷新缓冲区，不输出任何额外字符
- ens操纵符：插入一个空字符，然后刷新缓冲区
- unitbuf操纵符/nounitbuf操纵符：使用unitbuf操纵符后，任何输出立即刷新，无完成，直到使用nounitbuf操纵符
- 一个istream可以关类一个ostream；也可以将一个ostream关联到一个ostream
- 一个流最多关联**到**一个流，但多个流可以同时关联到同一个ostream：`cin.tie(&cout)`



## 文件输入输出

- 除`iostream`外，`fstream`特有的操作

| 操作                      | 解释                                                         |
| ------------------------- | ------------------------------------------------------------ |
| `fstream fstrm;`          | 创建一个未绑定的文件流。`fstream`是头文件`fstream`中定义的一个类型 |
| `fstream fstrem(s);`      | 打开名为`s`的文件，文件名可以是`string`类型或C风格字符串。默认模式与文件里类型有关 |
| `fstream fstrm(s, mode);` | 按照直到模式打开文件                                         |
| `fstrm.open(s)`           | 打开名为`s`的文件，模式与文件流类型有关                      |
| `fstrm.close()`           | 关闭文件流绑定的文件                                         |
| `fstrm.is_open()`         | 返回`bool`，指示文件里关联的文件是否打开成功且未关闭         |

### 使用文件流对象

- 定义：

```C++
ifstream in(infile);		//ifstream流对象且关联文件
ofstream out;				//未关联文件
out.open(ifile + ".copy")	//关联文件
```

- 使用`iostream&`的地方可以使用`fstream`对象
- 当一个`fstream`对象离开其作用域时，与之关联的文件会自动关闭

### 文件模式

- 文件模式与含义

| 文件模式 | 解释                                                |
| -------- | --------------------------------------------------- |
| `in`     | 读方式打开                                          |
| `out`    | 写方式打开；只有·`out`时默认配置`trunc`             |
| `app`    | 每次写操作时候定位到文件末尾；不能与`trunc`同时出现 |
| `ate`    | 打开时定位到文件末尾                                |
| `trunc`  | 截断文件；必须与`out`同时出现                       |
| `binary` | 以二进制形式打开                                    |

- 打开已有数据文件的唯一方法：显示指定`app`或`in`



## String流

- `sstream`内对象继承自`iostream`；除继承外的操作

| 操作               | 解释                           |
| ------------------ | ------------------------------ |
| `sstream strm;`    | strm是未绑定stringstream对象。 |
| `sstream strm(s);` | 保存一个`s`字符串的拷贝        |
| `strm.str()`       | 获取保存的string的拷贝         |
| `strm.str(s)`      | 设置stirng的拷贝               |

- 使用istringstream对象对整行数据进行处理
- 使用ostringstream对象，存放验证过程中的数值，直到所有验证结束后全部输出