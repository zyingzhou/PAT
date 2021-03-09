/**
* PAT1086
* Author: zhiying
* Date: 2021/3/5
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>

int main(){
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    int c = a * b;

    while(c >= 10){
        printf("%d", c % 10);
        c /= 10;
    }
    printf("%d\n", c);
    return 0;
}


