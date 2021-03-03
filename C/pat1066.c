/**
* pat 1066
* Author: zhiying
* Date: 2021/3/3
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

void imp(int *colors[], int len, int n, int low, int high, int replace);
void free_memory(int *colors[], int len);
void print(int *colors[], int len, int n);

int main(){
    int m = 0;
    int n = 0;
    int low = 0;
    int high = 0;
    int replace = 0;
    scanf("%d %d %d %d %d", &m, &n, &low, &high, &replace);

    int *colors[m];

    for (int i = 0; i < m; i ++){
        colors[i] = (int *)malloc(sizeof(int) * n);

        if (colors[i] != NULL){

            for (int j = 0; j < n; j ++){
                scanf("%d", colors[i] + j);
            }
        }
    }

    imp(colors, m, n, low, high, replace);
    print(colors, m, n);
    free_memory(colors, m);

    return 0;
}

void imp(int *colors[], int len, int n, int low, int high, int replace){

    for (int i = 0; i < len; i++){

        for (int j = 0; j < n; j ++){

            if (*(colors[i] + j) >= low && *(colors[i] + j) <= high){
                *(colors[i] + j) = replace;
            }
        }
    }
}

void free_memory(int *colors[], int len){

    for (int i = 0; i < len; i++){
        free(colors[i]);
    }
}

void print(int *colors[], int len, int n){

    for (int i = 0; i < len; i++){

        for (int j = 0; j < n; j ++){
            printf("%03d", *(colors[i] + j));

            if (j != n-1){
                printf(" ");
            } else{
                printf("\n");
            }
        }
    }
}