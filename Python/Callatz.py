#! /usr/bin/env python
# coding:utf-8
"""

Author: zhiying
Date: 2019.6.30
Description: 关注志颖博客(www.zhouzying.cn),一起探讨爬虫技术！

"""


def cal(n):
    count = 0
    while 1:
        if n == 1:
            print(count)
            break
        else:
            n //= 2
            count += 1
            if n == 1:
                print(count)
                break
            if n % 2 != 0:
                n = 3 * n + 1


def main():
    n = eval(input())

    if n % 2 == 0:
        cal(n)
    else:
        if n == 1:
            cal(n)
        else:
            n = 3 * n + 1
            cal(n)


if __name__ == '__main__':
    main()
