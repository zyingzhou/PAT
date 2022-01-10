/**
* pat1098
* Author: zhiying
* Date: 2022/1/10
* Copyright (c) 2022 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

int find_low(int *a, int len);
int find_height(int *a, int len);
int get_distance(int *a[], int len);

int main(){
    int n = 1;
    scanf("%d", &n);
    int *nums[2];
    for (int i = 0; i < 2; i ++){
        nums[i] = (int *)malloc(sizeof(int)*n);
        for(int j = 0; j < n; j++){
            scanf("%d", nums[i] + j);
        }
    }

    int low = find_low(nums[0], n);
    int height = find_height(nums[1], n);
    int distance = low - height;

    if (low > height){
        printf("Yes %d\n", distance);
    } else{
        printf("No %d\n", abs(distance) + 1);
    }

    free(nums[0]);

    return 0;
}

int find_low(int *a, int len){
    int *tmp = a;

    int low = *tmp;

    for (int i = 1; i < len; i++){

        if (*(tmp + i) < low){
            low = *(tmp + i);
        }
    }

    return low;
}

int find_height(int *a, int len){
    int *tmp = a;

    int height = *tmp;

    for (int i = 1; i < len; i++){

        if ( *(tmp + i) > height){

            height = *(tmp + i);
        }
    }

    return height;
}
int get_distance(int *a[], int len){

    int distance = *a[0] - *a[1];

    for (int i = 1; i < len;i ++){

        if (distance > (*(a[0] + i) - *(a[1] + i))){

            distance = *(a[0] + i) - *(a[1] + i);
        }
    }

    return distance;
}

