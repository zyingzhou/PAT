/**
* pat1012
* Author: zhiying
* Date: 2021.2.25 21:33
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char find_A1(int *nums, int len, int *result);
char find_A2(int *nums, int len, int *result);
char find_A3(int *nums, int len, int *result);
char find_A4(int *nums, int len, int *result, int *index);
char find_A5(int *nums, int len, int *result);

int is_even(int num);
void test_is_even();

int main(){
    int n;
    scanf("%d", &n);
    int *nums = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++){
        scanf("%d", nums + i);
    }

    int result = 0;
    int idx = 1;
    // A1
    if (find_A1(nums, n, &result) == 'N'){
        printf("N ");
    } else{
        printf("%d ",result);
    }

    // A2
    if (find_A2(nums, n, &result) == 'N'){
        printf("N ");
    } else{
        printf("%d ",result);
    }

    // A3
    if (find_A3(nums, n, &result) == 'N'){
        printf("N ");
    } else{
        printf("%d ",result);
    }

    // A4
    if (find_A4(nums, n, &result, &idx) == 'N'){
        printf("N ");
    } else{
        if (result % idx == 0){
            printf("%d ",result / idx);
        } else{
            printf("%.1f ", (float)result / (float)idx);
        }

    }

    // A5
    if (find_A5(nums, n, &result) == 'N'){
        printf("N\n");
    } else{
        printf("%d\n",result);
    }

    free(nums);

    return 0;
}

char find_A1(int *nums, int len, int *result){
    int *tmp = nums;
    int all = 0;

    int idx = 0;
    for (int i = 0; i < len; i++){
        if (*(tmp + i) % 5 == 0 && is_even(*(tmp + i))){
            idx++;
            all += *(tmp + i);
        }
    }

    if (idx != 0){
        *result = all;
        return 'O';
    } else{
        return 'N';
    }

}

char find_A2(int *nums, int len, int *result){
    int *tmp = nums;
    int all = 0;

    int idx = 0;
    for (int i = 0; i < len; i++){

        if (*(tmp + i) % 5 == 1){
            idx++;
            if (!is_even(idx)){
                all += *(tmp + i);
            } else{
                all -= *(tmp + i);
            }
        }

    }

    if (idx != 0){
        *result = all;
        return 'O';
    } else{
        return 'N';
    }
}

char find_A3(int *nums, int len, int *result){
    int *tmp = nums;

    int idx = 0;
    for (int i = 0; i < len; i++){
        if (*(tmp + i) % 5 == 2){
            idx++;
        }
    }

    if (idx != 0){
        *result = idx;
        return 'O';
    } else{
        return 'N';
    }
}
char find_A4(int *nums, int len, int *result, int *index){
    int *tmp = nums;
    int all = 0;
    int average = 0;

    int idx = 0;
    for (int i = 0; i < len; i++){
        if (*(tmp + i) % 5 == 3){
            idx++;
            all += *(tmp + i);
        }
    }

    if (idx != 0){
        *result = all;
        *index = idx;
        return 'O';
    } else{
        return 'N';
    }

}
char find_A5(int *nums, int len, int *result){
    int *tmp = nums;
    int max = 0;

    int idx = 0;
    for (int i = 0; i < len; i++){
        if (*(tmp + i) % 5 == 4){
            idx++;

            if (*(tmp + i) > max){
                max = *(tmp + i);
            }
        }
    }

    if (idx != 0){
        *result = max;
        return 'O';
    } else{
        return 'N';
    }

}

int is_even(int num){

    return num % 2? 0: 1;
}

void test_is_even(){
    assert(is_even(1) == 0);
    assert(is_even(2) == 1);
    assert(is_even(3) == 0);
    assert(is_even(10) == 1);
    assert(is_even(101) == 0);
    printf("is_even函数测试通过\n");
}
