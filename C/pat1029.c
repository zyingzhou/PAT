/**
* 
* Author: zhiying
* Date: 2021/3/6
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

#define N 2
void cmp(char *str[]);
// 数组去重
//void unique(char *s, int len);
void toUppercase(char *str);
char toUppercase_v2(char s);

int main(){

    char *str[N];

    for (int i = 0; i < N; i ++){
        str[i] = (char *)malloc(sizeof(char) * 81);

        if (str[i] != NULL){
            scanf("%s", str[i]);
        }
    }

    cmp(str);
    free(str[0]);
    free(str[1]);
    return 0;
}

void cmp(char *str[]){
    int i = 0;
    int delta = 0;

    char nums[81];
    int j = 0;
    while(*(str[0] + i) != '\0'){

        if (*(str[0] + i) != *(str[1] + i -delta)){
            delta ++;
            // 转换为大写字母
            *(str[0] + i) = toUppercase_v2(*(str[0] + i));

//            if (j == 0){
//
//                printf("%c", *(str[0] + i));
//            }
            int repeated = 0;
            // 查询
            for (int m = 0; m < j; m ++){

                if (*(str[0] + i) == nums[m]){
                    repeated = 1;
                    break;
                }
            }
            nums[j] = *(str[0] + i);
            if (!repeated){
                printf("%c", *(str[0] + i));
            }
            j++;

        }

        i++;
    }
}

// 小写字母转换成大写字母
void toUppercase(char *str){
    char* tmp = str;
    int i = 0;

    while (*(tmp + i) != '\0'){

        if (*(tmp + i) >= 'a' && *(tmp + i) <= 'z'){
            *(tmp + i) = (char)(*(tmp + i)-32);
        }
        i++;
    }

}

char toUppercase_v2(char s){
    char tmp = s;

    if (tmp >= 'a' && tmp <= 'z'){
        tmp = (char)(tmp-32);
    }

    return tmp;
}