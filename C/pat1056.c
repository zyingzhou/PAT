/**
* pat1056
* Author: zhiying
* Date: 2021.3.1 20:10
*/
#include <stdio.h>

int calculate(const int *nums, int len);
void input(int *a,int *len);

int main(){
    int len = 0;
    scanf("%d", &len);
    int nums[len];

    for (int i = 0; i < len; i++){
        scanf("%d", &nums[i]);
    }

    int all = calculate(nums, len);
    printf("%d\n", all);
    return 0;
}

int calculate(const int *nums, int len){
    int all = 0;

    for(int i = 0; i < len; i++){

        for (int j = 0; j < len; j ++){

            if (i == j){
                continue;
            }
            all += *(nums + i) * 10 + *(nums + j);
        }
    }
    return all;
}

// 输入的整数个数未知时可用
void input(int *a,int *len){

    int cnt=0;
    int n=1;
    char ch;

    do{
        scanf("%d%c",a,&ch);
        a++;
        cnt++;
    }while((int)ch != 10); //  The last character is line feed whose ascii value is 10

    *len = cnt;
}