/**
* pat1097
* Author: zhiying
* Date: 2022/1/11
* Copyright (c) 2022 All rights reserved.
*/
#include <stdlib.h>
#include <stdio.h>

// 获取键盘输入

// 输出结果
// 右移
void shift_right(int *nums, int len, int offset, int fix);
//　计算列和
int *cal_all_columns(int *nums[], int len);
void input_num(int *nums[], int len);

int main(){
    int n = 1;
    int k = 0;
    int x = 0;
    scanf("%d %d %d", &n, &k, &x);

    int *nums[n];
    input_num(nums, n);

    int cnt = 1;
    for (int m = 0; m < n; m++){

        if ((m + 1) % 2 == 1){
            shift_right(nums[m],n, cnt, x);

            if (cnt == k){
                cnt = 1;
                continue;
            }

            cnt++;
        }
    }

    int *result = cal_all_columns(nums, n);
    free(nums[0]);
    for (int i = 0; i < n; i++){
        printf("%d", *(result + i));

        if (i != n-1){
            printf(" ");
        }
    }
    printf("\n");

    free(result);
    return 0;
}

// 右移
void shift_right(int *nums, int len, int offset, int fix) {
    // 往右移
    for (int i = 0; i < len - offset; i++){
        *(nums + len - 1 - i) = *(nums + len -1 -offset - i);
    }

    // 填充
    for (int j = 0; j < offset; j++){
        *(nums + j) = fix;
    }
}
//　计算列和
int *cal_all_columns(int *nums[], int len){

    int *columns = (int *)malloc(sizeof(int)* len);

    for (int i = 0;i < len; i++){
        int column = 0;

        for (int j = 0; j < len; j++){

            column += *(nums[j] + i);
        }
        *(columns + i) = column;
    }

    return columns;
}

void input_num(int *nums[], int len){

    for (int i = 0; i < len ; i++){
        nums[i] = (int *)malloc(sizeof(int) * len);

        for (int j = 0; j < len; j++){
            scanf("%d", nums[i] + j);
        }
    }
}
