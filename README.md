# PAT (Basic Level) Practice （中文）
## 1.卡拉兹(Callatz)猜想：
> 对任何一个正整数 n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把 (3n+1) 砍掉一半。这样一直反复砍下去，最后一定在某一步得到 n=1。卡拉兹在 1950 年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证 (3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……
> 我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过 1000 的正整数 n，简单地数一下，需要多少步（砍几下）才能得到 n=1？  
> 
> 实现： 
* [Python](/Python/Callatz.py "Python实现") 
* [C](/C/pat1001.c "C语言实现")


## 2.写出这个数  
> 读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。 
> 
> 输入格式：
> 每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10 100。 
> 
> 输出格式：
> 在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
> 
> 输入样例：
> 1234567890987654321123456789 
>
> 输出样例：
> yi san wu 
> 
> 实现：
* [Python](/Python/pat1002.py "Python实现") 
* [C](/C/pat1002.c "C语言实现")


## 4.成绩排名
> 读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。 
> 
> 实现: 
* [C](/C/pat1004.c "C语言实现")


## 6.换个格式输出整数
> 让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10），换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

> 
> 实现:
* [C](/C/pat1006.c "C语言实现")


## 8.数组元素循环右移问题 
> 一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，将每个整数循环向右移M（≥0）个位置，即将A中的数据由(A0​​ A1...AN−1)变换为（AN−M⋯AN−1 A0 A1⋯AN−M−1）最后M个数循环移至最前面的M个位置）。如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

> 
> 实现:
* [C](/C/pat1008.c "C语言实现")
​​

## 9.说反话
> 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
> 
> 实现:
* [C](/C/pat1009.c "C语言实现")


## 11.A+B 和 C
> 给定区间 [−2​的31次方​​,2​的31次方​​] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。
> 
> 实现:
* [C](/C/pat1011.c "C语言实现")


## 14.福尔摩斯的约会
> 大侦探福尔摩斯接到一张奇怪的字条：我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。 
> 
> 实现:
* [C](/C/pat1014.c "C语言实现")


## 16.部分A+B 
> 正整数 A 的“D
​A
​​ （为 1 位整数）部分”定义为由 A 中所有 D
​A
​​  组成的新整数 P
​A
​​ 。例如：给定 A=3862767，D
​A
​​ =6，则 A 的“6 部分”P
​A
​​  是 66，因为 A 中有 2 个 6。

> 现给定 A、D
​A
​​ 、B、D
​B
​​ ，请编写程序计算 P
​A
​​ +P
​B
​​ 。
> 
> 实现:
* [C](/C/pat1016.c "C语言实现")

## 21.个位数统计
> 给定一个 k 位整数 N=d
​k−1
​​ 10
​k−1
​​ +⋯+d
​1
​​ 10
​1
​​ +d
​0
​​  (0≤d
​i
​​ ≤9, i=0,⋯,k−1, d
​k−1
​​ >0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定 N=100311，则有 2 个 0，3 个 1，和 1 个 3。

输入格式：
每个输入包含 1 个测试用例，即一个不超过 1000 位的正整数 N。

输出格式：
对 N 中每一种不同的个位数字，以 D:M 的格式在一行中输出该位数字 D 及其在 N 中出现的次数M。要求按D的升序输出。　

> [题目链接](https://pintia.cn/problem-sets/994805260223102976/problems/994805300404535296 "个位数统计") 

> 实现:
* [C](/C/pat1021.c "C语言实现")

## 22.D进制的A+B 
> 输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：
输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：
输出 A+B 的 D 进制数。

输入样例：
123 456 8
输出样例：
1103

> [题目链接](https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344 "D进制的A+B")

> 实现：
* [C](/C/pat1022.c "C语言实现")

## 23.组个最小数
> 给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意 0 不能做首位）。例如：给定两个 0，两个 1，三个 5，一个 8，我们得到的最小的数就是 10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：
输入在一行中给出 10 个非负整数，顺序表示我们拥有数字 0、数字 1、……数字 9 的个数。整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。

输出格式：
在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558

> 
> [题目链接](https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560 "组个最小数")

> 实现：
* [C](/C/pat1023.c "C语言实现")

## 26.程序运行时间

> 要获得一个 C 语言程序的运行时间，常用的方法是调用头文件 time.h，其中提供了 clock() 函数，可以捕捉从程序开始运行到 clock() 被调用时所耗费的时间。这个时间单位是 clock tick，即“时钟打点”。同时还有一个常数 CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得一个函数 f 的运行时间，我们只要在调用 f 之前先调用 clock()，获得一个时钟打点数 C1；在 f 执行完成后再调用 clock()，获得另一个时钟打点数 C2；两次获得的时钟打点数之差 (C2-C1) 就是 f 运行所消耗的时钟打点数，再除以常数 CLK_TCK，就得到了以秒为单位的运行时间。

这里不妨简单假设常数 CLK_TCK 为 100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。

输入格式：
输入在一行中顺序给出 2 个整数 C1 和 C2。注意两次获得的时钟打点数肯定不相同，即 C1 < C2，并且取值在 [0,10
​7
​​ ]。

输出格式：
在一行中输出被测函数运行的时间。运行时间必须按照 hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒。

输入样例：
123 4577973
输出样例：
12:42:59

> [题目链接](https://pintia.cn/problem-sets/994805260223102976/problems/994805295203598336 "程序运行时间")

> 实现：
* [C](/C/pat1026.c "C语言实现")