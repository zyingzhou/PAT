/**
* pat1021
* Author: zhiying
* Date: 2021.2.20 21:22
*/
#include <stdio.h>
#include <stdlib.h>

void mk_zero_not_first(int *arr, int len);

int main() {
    int arr[10] = {0};
    int len = 0;
    for (int i=0;i<10;i++) {
        scanf("%d", &arr[i]);
        len += arr[i];
    }

    int *a = (int *)malloc(sizeof(int)*len);
    int *t = a;

    for (int i=0;i<10;i++){

        if (arr[i] == 0){
            continue;
        } else{
            for (int j = 0;j<arr[i];j++){
                *t = i;
                t++;
            }
        }
    }

    mk_zero_not_first(a, len);

    for (int i = 0;i<len;i++){
        printf("%d",*(a+i));
    }

    free(a);
    printf("\n");
    return 0;
}
/**
 * mk_zero_not_first - 使0不为第１位数
 * @param arr: 输入的指针
 * @param len: 数组的长度
 */
void mk_zero_not_first(int *arr, int len){
    int *tmp = arr;
    if (*tmp !=0){
        return;
    }else {
        for (int i=0;i<len;i++) {
            if (*(tmp + i) != 0){
                int t = *(tmp + i);
                *tmp = t;
                *(tmp + i) = 0;
                break;
            }
        }
    }
}