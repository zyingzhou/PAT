#! /usr/bin/env python
# coding:utf-8
"""

Author: zhiying
Date: 2019.7.31
Description: 关注志颖博客(www.zhouzying.cn),一起探讨爬虫技术！

"""


# split the input number.
def split_number(nums):
    i = 0
    item = {}
    if nums < 10:
        item[i] = nums
    else:
        while nums != 0:
            item[i] = nums % 10
            i += 1
            if nums // 10 != 0:
                nums = nums // 10
                if nums < 10:
                    item[i] = nums
                    nums = nums // 10
    return item


# make sum
def make_sum(splited_nums):
    sums = 0
    for j in range(len(splited_nums)):
        sums += splited_nums[j]
    return sums


def main():
    pinyin = {0: 'ling', 1: 'yi', 2: 'er', 3: 'san', 4: 'si', 5: 'wu', 6: 'liu', 7: 'qi', 8: 'ba', 9: 'jiu'}
    num = eval(input("请输入一个整数：\n"))
    item = split_number(num)
    all_sums = make_sum(item)
    output_nums = split_number(all_sums)
    for j in range(len(output_nums)-1, -1, -1):
        key = output_nums[j]
        if j == 0:
            print(pinyin[key], end='\n')
        else:
            print(pinyin[key], end=' ')


if __name__ == '__main__':
    main()

