/**
* 
* Author: zhiying
* Date: 2022/1/17
* Copyright (c) 2022 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * find_max(char *str[], int len);
int cmp(char *str1, char *str2);
int find_schoolmates(char *schoolmates[], int len1, char *customers[], int len2, char *result[]);
int find_schoolmates_v2(char *schoolmates[], int len1, char *customers[], int len2, char *result[]);
void str_part(char *dest, char *src, int from, int to);
void swap(char *str1, char *str2);
void bubblesort(char *strs[], int len);
int binarysearch(char *strs[], int len, char *str, int *idx);

int main(){

    int n = 0;
    scanf("%d", &n);
    char *schoolmates[n];
    char *result[n];

    for (int i = 0; i < n; i++){
        schoolmates[i] = (char *)malloc(sizeof(char) * 19);
        scanf("%s", schoolmates[i]);
    }

    int m = 0;
    scanf("%d", &m);
    char *customers[m];
    for (int i = 0; i < m; i++){
        customers[i] = (char *)malloc(sizeof(char) * 19);
        scanf("%s", customers[i]);
    }
    bubblesort(schoolmates, n);
//    int ret = find_schoolmates(schoolmates,n, customers, m,result);
    int ret = find_schoolmates_v2(schoolmates,n, customers, m,result);
    char *max = NULL;

    if (ret == 0){
//        max = find_max(customers, m);
        bubblesort(customers, m);
        max = schoolmates[m-1];
    } else{
        bubblesort(result,ret);
        max = result[ret - 1];
//        max = find_max(result, ret);
    }
    printf("%d\n", ret);
    printf("%s\n", max);
    free(schoolmates[0]);
    free(customers[0]);
    free(result[0]);

    return 0;
}

/**
 *
 * @param str
 * @param len
 * @return
 */
char * find_max(char *str[], int len){
       char max[8];
       int idx = 0;
       char birth[8];
       str_part(max,str[0], 7, 14);
       for(int i = 1; i < len; i++){
           str_part(birth,str[i], 7, 14);

           if (strcmp(birth, max) < 0){
               str_part(max,str[i], 7, 14);
               idx = i;
           }
       }
    return str[idx];
}

/**
 *
 * @param str1 string1
 * @param str2 string2
 * @return  =0 equal
 */
int cmp(char *str1, char *str2){

    return strncmp(str1, str2, 18);
}

int find_schoolmates(char *schoolmates[], int len1, char *customers[], int len2, char *result[]){
    int ret = 0;

    for (int i = 0; i < len2; i++){

        for (int j = 0; j < len1; j++){

            if (!cmp(customers[i], schoolmates[j])){
                result[ret] = (char *)malloc(sizeof(char)*19);
                strncpy(result[ret], schoolmates[j],19);
                ret++;
            }

        }
    }

    return ret;
}

/**
 * copy char from-to of src to dest.
 * @param dest
 * @param src
 * @param from
 * @param to
 */
void str_part(char *dest, char *src, int from, int to){
    int len = to -from + 1;
    char *tmp = src;
    from--;

    while (from>0){
        from--;
        tmp++;

    }
    strncpy(dest, tmp, len);
}

void swap(char *str1, char *str2){
    char tmp[19];
    strcpy(tmp, str1);
    strcpy(str1, str2);
    strcpy(str2, tmp);
}
// from young to old
void bubblesort(char *strs[], int len){
    char max[8];
    char birth[8];
    for (int sorted = 0; sorted = !sorted; len--) {
        for (int i = 1; i < len; i++) {
            str_part(max, strs[i-1], 7, 14);
            str_part(birth, strs[i], 7, 14);

            if (strcmp(birth, max) > 0) {
                swap(strs[i], strs[i-1]);
                sorted = 0;
            }
        }
    }

}

/*
 * return 0 not found
 *        1 found
 * */
int binarysearch(char *strs[], int len, char *str, int *idx){
    int low = 0;
    int mid;
    int high = len - 1;
    char birth[8];
    char tmp[8];
    str_part(birth,str, 7, 14);

    while (low <= high){
        mid = (low + high) / 2;
        str_part(tmp,strs[mid], 7, 14);
        if (strncmp(tmp, birth, 8) == 0){
            *idx = mid;
            return 1;
        }
        if (strcmp(tmp, birth) > 0){
            low = mid + 1;
        } else{
            high = mid -1;
        }
    }
    return 0;

}

int find_schoolmates_v2(char *schoolmates[], int len1, char *customers[], int len2, char *result[]){
    int ret = 0;
    int idx = 0;

    for (int i = 0; i < len2; i++){
        if (binarysearch(schoolmates, len1, customers[i], &idx)){
            result[ret] = (char *)malloc(sizeof(char)*18);
            strncpy(result[ret], schoolmates[idx],18);
            ret++;
        }


    }

    return ret;
}
