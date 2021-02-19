/*
* pat1021
* Author: zhiying
* Date: 2021.2.19 20:27
*/
#include <stdio.h>
#include <stdlib.h>

int convert(int n, int d, int* nums);

int main() {
    int a=0;
    int b=0;
    int d=1;
    int *nums = (int*)malloc(sizeof(int)*100);
    scanf("%d %d %d", &a,&b,&d);
    int len = convert((a+b),d,nums);
    for (int j=len;j>=0;j--){
        printf("%d",*(nums+j));
    }
    printf("\n");
    free(nums);

    return 0;
}

/**
 * convert - 将整数转换成n进制数
 * @n: 需要转换的数
 * @d: 进制数 1< d <= 10;
 *
 */
int convert(int n, int d, int* nums){
    int idx=0;
    int* tmp = nums;

    while(n >= d){
        tmp[idx] = n % d;
        n /= d;
        idx++;
    }

    tmp[idx] = n;

    return idx++;
}