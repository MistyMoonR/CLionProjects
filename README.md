## 中文版C++ primer 错误太多，受不了:mask::mask::mask:  

### version ：9.3.8


-----------------------
|Author|MistyMoon|
|---|---
|E-mail|MistyMoonR@outlook.com

-----------------------
### 笔记部分   
 

**2019年篇**   


**8.18**   
P26 类的公共接口与私有实现代码的分离-> information hiding  

**8.20**   
看到 2.4 面向对象的设计, 感觉C++ primer第二章太啰嗦 暂时转移到 -> Accelerate C++   

**8.21**  
`const`: const修饰的数据类型是指常类型，常类型的变量或对象的值是不能被更新的。  
`void`: 中文翻译为“无类型”。常用在程序编写中对定义函数的参数类型、返回值、函数中指针类型进行声明。  
`string`: 是编程语言中的字符串，字符串是一个特殊的对象，属于引用类型。 在java、C#中，String类对象创建后，字符串一旦初始化就不能更改，因为string类中所有字符串都是常量，数据是无法更改，由于string对象的不可变，所以可以共享。
`explicit`: 可以阻止不应该允许的经过转换构造函数进行的隐式转换的发生。声明为explicit的构造函数不能在隐式转换中使用。  
`substr`: 是C++语言函数，主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度。  
`unsigned int`: 数据类型的变量只能存非负的值(0和更大整数).

**8.22**  
C++ 大学教程 P129-151 然后出发去新加坡  

**8.23**  
P151 6.1 代码撸完一半。困得不行，早睡早起

**8.24**  
P155-167 去南洋理工溜达了，真的是比西浦好一万倍。  
`setw(int n)`用来控制输出间隔。  
`srand` 函数是随机数发生器的初始化函数。原型：void srand(unsigned int seed);srand和rand()配合使用产生伪随机数序列。  
`enum` 枚举名{ 枚举值表 }; 在枚举值表中应罗列出所有可用值。这些值也称为枚举元素。  

**8.25**  
P167  环球影城溜达一天  
`default_random_engine` [随机数生成器](http://c.biancheng.net/view/638.html)  
`uniform_int_distribution` [离散均匀分布类](http://c.biancheng.net/view/639.html)   
  
**8.26**  
P172 跑去新加坡国家图书馆，找到 C++ how to program这本书  
堆栈(stack)有点看不懂，但会用。后面再仔细研究  
6.15的 引用和引用形参，概念模糊   

**8.27**  
P209-220  
`size_t` 是标准C库中定义的，应为unsigned int，在64位系统中为 long unsigned int  
`static` 有两种用法：面向过程程序设计中的static和面向对象程序设计中的static。前者应用于普通变量和函数，不涉及类；后者主要说明static在类中的作用。 

**8.28**  
P224

**8.29**  
升级了一下电脑 啥也没干

**8.30**  
咸鱼一天  

**8.31**  
回到苏州，收拾东西  
教程有些没用代码，迷惑？  

**9.1**  
收拾宿舍+领书  
P233 
京东上买了C++ Primer Plus，感觉中文版还是没英文版的好，先搁着。

**9.2**  
上课第一天，JAVA和C++还是比较像，，很快就完成作业  

**9.3**  
蛤为路由器翻车  
三屏 三倍欢乐  
编译不通过 看不懂错误  

**9.4**  
忘了写东西

**9.5**  
千兆局域网传输get，路由器可能要刷固件一下  
去公司溜达了下


**2020年篇**   

**3.7**  
时隔半年，重新拾起C，主要是因为操作系统这个课程。。。
差点忘了git这么用

**3.10**  
完成CSE108的Exercise 3.1 和3.2      
分别是Tout hostel和Tug of War

**3.16**  
这几天全都在赶report    
真的很想吐槽Assignment 3.2, 判断条件很奇怪。    
算了不管了。SB玩意  

**3.18**  
头疼一天，ipad也没电，只好先看看C  
Lab4的 Array部分 

**3.24**  
前段时间基本再画板子，画PCB真好玩。     
看来需要学点硬件的知识了        
正事：Lab5

**3.26**  
完成Lab5

**3.31**  
完成Lab6        
高考推迟一个月，有点喜感。。。。

-----------------------

### Notes
[GoodNotes](GoodNotes/README.md)

-----------------------

### C++ primer Information

[C++ Primer 英文版](C%2B%2B%20Primer.pdf) 需要下载   
[C++ Primer 中文版](C%2B%2B入门到精通%20.pdf) 需要下载  
Accelerate C++（C++ 大学教程) 单个文件超过100MB限制，暂时没搞清LTS怎么用  
[C++ Primer 代码](https://github.com/Mooophy/Cpp-Primer)  
[习题答案](https://wenku.baidu.com/view/e347512f2af90242a895e549.html)  

-----------------------

### Git Tutorial
```
touch README.md  
git init  
git add README.md  
git commit -m " xxx "  
git remote add origin git@github.com
git push -u origin master  
 
git add .  //添加需要提交的文件  
git commit -m " xxx "  
git push origin master  

// 回滚旧版本
git log  
git reset --hard xxxxxxxxxx  

```
[Github md编辑](https://github.com/guodongxiaren/README)

-----------------------

### Pycharm/Idea/Clion常用快捷键

* ⌘ ——> Command  
* ⇧ ——> Shift  
* ⌥ ——> Option  
* ⌃ ——> Control  
* ↩ ——> Return/Enter  

```
Control + R 运行
Command + 鼠标 简介
Command + R  替换  
Command + R 文件内替换
Control + J 快速查看文档
Command + Shift + F 全局查找  
Command + Shift + R 全局替换  
Command + Shift + Enter  自动结束代码，行末自动添加分号
```
Reference:   https://blog.csdn.net/Architect_CSDN/article/details/80235658
