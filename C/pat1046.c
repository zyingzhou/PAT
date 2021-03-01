/**
* pat1046
* Author: zhiying
* Date: 2021.3.1 7:55
*/
#include <stdio.h>
#include <stdlib.h>

void free_mem(int *record[], int len);
void cmp(int *record[], int len, int *failed);

int main(){
    int n;
    scanf("%d", &n);
    int *records[n];
    int failed[2] = {0};

    for (int i = 0; i < n; i++){
        records[i] = (int *)malloc(sizeof(int) * n);

        if (records[i] != NULL){

            for (int j = 0; j < 4; j++){
                scanf("%d", records[i] + j);
            }
        }

    }
    cmp(records, n, failed);
    printf("%d %d\n", failed[0], failed[1]);
    free_mem(records, n);
    return 0;
}

void free_mem(int *record[], int len){

    for (int i = 0; i< len; i++){
        free(record[i]);
    }
}

void cmp(int *record[], int len, int *failed){
    int all = 0;

    for (int i = 0; i < len; i++){

        all = *record[i] + *(record[i] + 2);
        if (*(record[i] + 1) == all && *(record[i] + 3) != all){
            *(failed + 1) += 1;
        } else if (*(record[i] + 1) != all && *(record[i] + 3) == all){
            *(failed) += 1;
        }else{
            continue;
        }
    }
}