/**
*  pat1076
* Author: zhiying
* Date: 2021/3/5 8:45
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 8

void get_wifi(char *str[], int len, int *wifi);
void print_wifi(int *wifi, int len);
int convert(char ch);
void free_mem(char *str[], int len);

int main(){
    int n = 0;
    scanf("%d", &n);
    char *str[n];
    int *wifi = (int *)malloc(sizeof(int) * n);
    char ch;
    // ignore \n;
    scanf("%c", &ch);

    for (int i = 0; i < n; i++){
        str[i] = (char *)malloc(sizeof(char) * N);

        if (str[i] != NULL){

            int j = 0;
            do{

                scanf("%c",str[i] + j);
                scanf("%c", &ch);
                j++;
            }while ((int)ch != 10);
        }

    }

    get_wifi(str, n, wifi);
    print_wifi(wifi, n);

    free_mem(str, n);
    free(wifi);

    return 0;
}

void get_wifi(char *str[], int len, int *wifi){
    int *tmp = wifi;

    for (int idx = 0; idx < len; idx ++){

        for (int i = 0; i < N; i += 2){

            if (*(str[idx] + i + 1) == 'T'){

                *(tmp + idx) = convert(*(str[idx] + i));
                break;
            }
        }
    }

}
void print_wifi(int *wifi, int len){
    int *tmp = wifi;

    for (int i = 0; i < len; i++){
        printf("%d", *(tmp + i));
    }
    printf("\n");
}

int convert(char ch){
    int ret = 0;

    switch (ch){
        case 'A': ret = 1;break;
        case 'B': ret = 2;break;
        case 'C': ret = 3;break;
        default: ret = 4;
    }

    return ret;
}
void free_mem(char *str[], int len){

    for (int i = 0; i < len; i ++){

        free(str[i]);
    }
}

