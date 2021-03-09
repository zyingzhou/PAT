/**
* pat1091
* Author: zhiying
* Date: 2021/3/5
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

void check(int num);
int cmp(int a, int b);

int main(){
    int m = 0;
    scanf("%d", &m);

    int *nums = (int *)malloc(sizeof(int)*m);

    for (int i = 0; i < m; i++){
        scanf("%d", nums + i);
    }

    for(int i = 0; i < m; i++){
        check(*(nums + i));
    }
    free(nums);
    return 0;
}

void check(int num){
    int res = 0;
    int flag = 0;
    for (int i = 0; i <= 9; i++){
        res = i * num * num;
        if (cmp(res, num) == 1){
            flag = 1;
            printf("%d %d\n", i, res);
            break;
        }

    }

    if (flag == 0){
        printf("No\n");
    }

}

int cmp(int a, int b){
    int ret = 0;
    // b <=1000
    if (b <= 10){
        ret = (a - b) % 10 ? 0 : 1;
    } else if(b > 10 && b <= 100){
        ret = (a - b) % 100 ? 0 : 1;
    } else{
        ret = (a - b) % 1000 ? 0 : 1;
    }
    return ret;
}