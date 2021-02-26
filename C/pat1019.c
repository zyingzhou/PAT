/**
* pat1019
* Author: zhiying
* Date: 2021.2.25 22:33
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define  N 5

void sort_c(char *a, char *a_descend, char *a_ascend);
void subtract(char *a_descend, char *a_ascend, char *result);
void swap(char *c1, char *c2);
int is_all_same(char *a);
void copy_array(char *dest, char *src);

int main(){
    char a[N];
    scanf("%s", a);
    // 判断a的位数,少于4位则后面补齐0
    if (strlen(a) != N - 1){
        for (int i = strlen(a); i < N - 1; i ++){
            a[i] = '0';
        }
        // 最后一位放\0
        a[N - 1] = '\0';
    }
    char a_descend[N] = {'0','0','0','0','\0'};
    char a_ascend[N] = {'0','0','0','0','\0'};
    char result[N] = {'0','0','0','0','\0'};

    if (is_all_same(a)){
        printf("%s - %s = 0000\n", a, a);
    } else{
        do{
            sort_c(a, a_descend, a_ascend);
            subtract(a_descend, a_ascend, result);
            printf("%s - %s = %s\n", a_descend, a_ascend, result);
            copy_array(a, result);
        }while (strncmp(result, "6174", 4) != 0);
    }
    return 0;
}
void sort_c(char *a, char *a_descend, char *a_ascend){
    char *tmp = a;
    // descend
    for (int i = 0; i < N-2; i++){
        for (int j = i + 1; j < N-1; j++){

            if (*(tmp + i) < *(tmp + j)){
                swap(tmp + i, tmp + j);
            }
        }
    }

    strncpy(a_descend, a, 5);
    tmp = a;
    // ascend
    for (int i = 0; i < N-2; i++){
        for (int j = i + 1; j < N-1; j++){

            if (*(tmp + i) > *(tmp + j)){
                swap(tmp + i, tmp + j);
            }
        }
    }

    strncpy(a_ascend, a, 5);
}
void subtract(char *a_descend, char *a_ascend, char *result){
    int descend = atoi(a_descend);
    int ascend = atoi(a_ascend);

    int res = descend - ascend;
    int ctrl  = 0;
    if (res < 10){
        ctrl =3;
    } else if (res >= 10 && res < 100){
        ctrl = 2;
    } else if (res >= 100 && res < 1000){
        ctrl = 1;
    } else{
        ctrl = 0;
    }

    int i = 0;
    for (; i < ctrl; i++){
        *(result + i) = '0';
    }

    // 个位,十位,千位是从*(result + 3),分别往左
    int idx = N-2;
    while (res >= 10){
        *(result + idx) = (char)(res % 10 + 48);
        res /= 10;
        idx--;

        if (res < 10){
            *(result + i) = (char)(res % 10 + 48);
            idx--;
        }
    }

    // 最后添加\0
    *(result + 4) = '\0';
}
void swap(char *c1, char *c2){
    char tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

int is_all_same(char *a){
    int same = *a;
    int is_same = 0;
    int cnt = 0;
    for (int i = 1; i <= 3; i++){
        if (*(a + i) == same){
            cnt++;
        }
    }
    if (cnt == 3){
        is_same =  1;
    }
    return is_same;

}

/**
 * copy an array from another one -- deep copy
 * @param dest destination of array
 * @param src  source of another array
 */
void copy_array(char *dest, char *src){

    for (int i = 0; i < N; i++){
        *(dest + i) = *(src + i);
    }
}

