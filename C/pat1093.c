/**
* pat1093
* Author: zhiying
* Date: 2022/1/13 update 2022/03/17
* Copyright (c) 2022 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_str(char *str);
void do_unique(char *str);
void str_trim(char *str, char ch);


int main(){

    char *str1 = (char *)malloc(sizeof(char)*1000001*2);
    char *str2 = (char *)malloc(sizeof(char)*1000000 + 1);

    input_str(str1);
    input_str(str2);

    // 字符串去重
    do_unique(str1);
    do_unique(str2);
    // 字符串拼接
    strcat(str1,str2);
    free(str2);
    // 再去重
    do_unique(str1);
    printf("%s", str1);
//    test_str_trim();
    // 释放内存
    free(str1);
    return 0;
}

void do_unique(char *str){
    int len = strlen(str);
    char *p = str;
    for (int i = 0; i < len; i++){
        char ch = *p;
        p++;
        if(ch == '\n'){
            continue;
        }

        char *pch;
        pch = strchr(p, ch);
        while (pch != NULL){
            *pch = '\n';
            pch++;
            pch = strchr(pch, ch);
        }
    }

    str_trim(str, '\n');
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

void str_trim(char *str, char ch){
    int len = strlen(str);
    char *head = str;
    char *p = str;

    for(int i = 0; i < len; i++){

        if (*p != ch){
            *head = *p;
            head++;
        }
        p++;
    }
    *head = '\0';
}