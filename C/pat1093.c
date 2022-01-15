/**
* pat1093
* Author: zhiying
* Date: 2022/1/13
* Copyright (c) 2022 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_str(char *str);
void do_unique(char *str);
void str_joint(char *str1, char *str2);


int main(){

    char *str1 = (char *)malloc(sizeof(char)*1000001*2);
    char *str2 = (char *)malloc(sizeof(char)*1000000 + 1);

    input_str(str1);
    input_str(str2);

    // 字符串去重
    do_unique(str1);
    do_unique(str2);
    // 字符串拼接
    str_joint(str1, str2);
    // 再去重
    do_unique(str1);
    printf("%s", str1);
    // 释放内存
    free(str1);
    free(str2);
    return 0;
}

void do_unique(char *str){
    char *head = str;
    char *p = str;

    while (*p != '\n'){
        char ch = *p;
        char *tmp = p;
        tmp++;
        while (*tmp != '\n'){

            if (ch == *tmp){
                *tmp = '\n';
                tmp++;
                str_joint(head, tmp);
                tmp--;
                continue;
            }
            tmp ++;
        }
        p++;
    }
}

void str_joint(char *str1, char *str2){
    char *tmp = str1;

    while(*tmp != '\n'){
        tmp++;
    }

    while((*tmp++ = *str2++) != '\n');
    *tmp = '\0';

}

void input_str(char *str){
    char *tmp = str;

    char ch;
    scanf("%c", &ch);

    while (ch != '\n'){
        *tmp = ch;
        scanf("%c", &ch);
        tmp++;
    }
    // 末尾加上'\n'
    *tmp = ch;
}