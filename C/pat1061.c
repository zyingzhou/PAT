/**
* pat1061
* Author: zhiying
* Date: 2021.3.2 16:36
*/
#include <stdio.h>
#include <stdlib.h>
void imp(int *nums[], int *scores, int len, int cnt);
void free_mem(int *nums[], int len);

int main(){
    int n=0;
    int m = 0;
    scanf("%d %d", &n, &m);

    int *nums[n + 2];

    for (int i = 0; i < n + 2; i ++){
        nums[i] = (int *)malloc(sizeof(int) * m);

        if (nums[i] != NULL){

            for (int j = 0; j < m; j++){
                scanf("%d", nums[i] + j);
            }
        }
    }

    int scores[n];
    imp(nums, scores, n, m);

    for (int i =0; i < n; i ++){
        printf("%d\n", scores[i]);
    }
    free_mem(nums, n+2);
    return 0;
}

void imp(int *nums[], int *scores, int len, int cnt){
    int *grade = scores;

    for (int k = 0; k < len; k++){
        *(grade + k) = 0;
    }

    for (int i = 2; i < len + 2; i ++){

        for (int j = 0; j < cnt; j ++){

            if (*(nums[i] + j) == *(nums[1] + j)){
                *(grade + i - 2) += *(nums[0] + j);
            }
        }
    }
}

void free_mem(int *nums[], int len){

    for (int i =0; i < len; i ++){
        free(nums[i]);
    }
}