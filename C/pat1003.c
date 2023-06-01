/**
* 
* Author: zhiying
* Date: 2022/1/9
* Copyright (c) 2022 All rights reserved.
*/
#include <stdlib.h>
#include <stdio.h>

void input_str(char *strs[], int len);
void print_str(char *strs[], int len);
void init_point(char *strs[], int len);
void check(char *strs[], int *results, int len);
// 释放内存空间
void free_m(char *strs[], int len);
int have_other_words(char *str);

typedef struct {
    int value;
    int checked;
}Result;

int main(){
    int n = 0;
    scanf("%d", &n);
    char *strs[n];
    Result* result[n];

//    init_point(strs, n);
    input_str(strs, n);
    print_str(strs, n);

//    释放内存
    free_m(strs, n);
    return 0;
}

void input_str(char *strs[], int len){

    for (int i = 0; i < len ; i++){
        strs[i] = (char *)malloc(sizeof(char) * 101);
        scanf("%s", strs[i]);
    }
}
void print_str(char *strs[], int len){

    for (int i = 0; i < len ; i++){

        printf("%s\n", strs[i]);
    }

}
void check(char *strs[], int *results, int len);

void free_m(char *strs[], int len){
    for (int i = 0;i < len; i++){
        free(strs[i]);
    }
}

void init_point(char *strs[], int len){

    for(int i = 0;i < len; i++){
        strs[i] = NULL;
    }
}

int have_other_words(char *str){
    char *tmp = str;
    int i = 0;

    int ret = 0;

    while (*(tmp + i) != '\0'){

        if (*(tmp + i) != 'P' && *(tmp + i) != 'A' && *(tmp + i) != 'T'){
            ret = 1;
            break;
        }
    }

    return ret;
}