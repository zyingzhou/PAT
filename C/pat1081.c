/**
*  pat1081 10:20
* Author: zhiying
* Date: 2021/3/5
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_password(char *str[], int len);
void free_mem(char *str[], int len);
int isChar(char ch);
int isDigit(char ch);
int isDot(char ch);


int main(){
    int n = 0;
    scanf("%d", &n);

    char *str[n];

    for(int i = 0; i < n; i ++){
        str[i] = (char *)malloc(sizeof(char) * 81);

        if (str[i] != NULL){

            scanf("%s", str[i]);
        }
    }

    check_password(str, n);
    free_mem(str, n);

    return 0;
}

void check_password(char *str[], int len){

    for (int i = 0; i < len; i++){

        if (strlen(str[i]) < 6){
            printf("Your password is tai duan le.\n");
            continue;
        }

        int j = 0;
        int char_cnt = 0;
        int digit_cnt = 0;
        int dot_cnt = 0;
        int illegal = 0;

        while (*(str[i] + j) != '\0'){

            if (isChar(*(str[i] + j)) == 1){
                j++;
                char_cnt++;
                continue;
            } else if(isDigit(*(str[i] + j)) == 1){
                j++;
                digit_cnt++;
                continue;
            } else if(isDot(*(str[i] + j)) == 1) {
                j++;
                dot_cnt ++;
                continue;
            } else{
                printf("Your password is tai luan le.\n");
                illegal = 1;
                break;
            }

        }

        if (illegal == 1){
            continue;
        }

        if (char_cnt >= 1 && digit_cnt >= 1){
            printf("Your password is wan mei.\n");
            continue;
        }

        if (char_cnt >=1 && digit_cnt == 0){
            printf("Your password needs shu zi.\n");
            continue;
        }

        if (char_cnt == 0 && digit_cnt >= 1){
            printf("Your password needs zi mu.\n");
            continue;
        }
        // 全是字母,全是数字,全是小数点
        if (dot_cnt == strlen(str[i])){
            printf("Your password is tai luan le.\n");
            continue;
        }
    }

}
void free_mem(char *str[], int len){

    for (int i = 0; i < len; i++){
        free(str[i]);
    }
}

int isChar(char ch){
    int is_char = 0;

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        is_char = 1;
    }
    return is_char;
}
int isDigit(char ch){
    int is_digit = 0;

    if (ch >= '0' && ch <= '9'){
        is_digit = 1;
    }
    return is_digit;
}
int isDot(char ch){
    return ch == '.' ? 1 : 0;
}