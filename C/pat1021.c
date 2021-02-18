/*
* pat1021
* Author: zhiying
* Date: 2021.2.18 22:00
*/
#include <stdio.h>
#include <stdlib.h>

// 按字符输入　使用atoi()函数,该函数的头文件为stdlib.h
void counts_v2(char*a, int *b);
// 有效整数范围内有效
void counts(long long int n, int*a);

int main(){
    char *a = (char *)malloc(sizeof(char)*1001);
    int b[10] = {0};
    scanf("%s",a);
    counts_v2(a,b);
    //释放内存
    free(a);
    for (int i=0;i <10;i++){
        if (b[i] > 0){
            printf("%d:%d\n",i,b[i]);
        }

    }

    return 0;
}

/*
 * @b 指针b传入之前需要初始化为０
 */
void counts_v2(char*a, int *b){
    char *c = a;
    // 用于计算输入的位数
    int i = 0;
    // 指针指向尾巴
    while (*c != '\0'){
        i++;
        c++;
    }
    // 指针往左移动
    for (int j=0; j< i;j++) {
        c--;
        int n = atoi(c);
        b[n] += 1;
        *c = '\0';
    }
}

// 有效整数范围内有效
void counts(long long int n, int*a){
    long long int t = 0;
    t = n;

    while(t >= 10){
        int m = t % 10;
        a[m] += 1;
        t /= 10;
    }
    a[t] += 1;
}
