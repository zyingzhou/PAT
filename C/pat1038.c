/**
* 
* Author: zhiying
* Date: 2021/12/5
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int M = 0;
    int N = 0;
    scanf("%d", &M);
    int *nums[M];
    *nums = malloc(M * sizeof(int));
    // 初始化
    for(int i = 0; i < M ; i ++ ){
        *nums[i] = 0;
        scanf("%d", nums[i]);

    }
    printf("周志颖\n");
    free(nums);
    return 0;
}



