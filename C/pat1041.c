/**
* pat1041
* Author: zhiying
* Date: 2021.2.28 21:17
*/
#include <stdio.h>
#include <stdlib.h>

#define N 17

typedef struct{
    char card[N];
    int test_seat;
    int exam_seat;
}Examinee;

void search_seat(Examinee *exam[], int len0, int *test_seats, int len1);
void free_mem(Examinee *exam[], int len);

int main(){
    int n = 0;
    scanf("%d", &n);
    Examinee *examinees[n];
    int m = 0;

    for (int i = 0; i < n; i ++){
        examinees[i] = (Examinee *)malloc(sizeof(Examinee)*n);

        if (examinees[i] != NULL){
            scanf("%s", examinees[i]->card);
            scanf("%d %d", &examinees[i]->test_seat, &examinees[i]->exam_seat);
        }
    }
    scanf("%d", &m);
    int set[m];

    for (int i = 0; i < m; i++){
        scanf("%d", &set[i]);
    }

    search_seat(examinees, n, set, m);
    free_mem(examinees, n);

    return 0;
}

void search_seat(Examinee *exam[], int len0, int *test_seats, int len1){
//    Examinee *tmp = exam[0];
    int *seat = test_seats;

    for (int i = 0; i < len1; i++){

        for (int j = 0; j < len0; j ++){

            if (exam[j]->test_seat == *(seat + i)){
                printf("%s %d\n", exam[j]->card, exam[j]->exam_seat);
            }
        }
    }
}

void free_mem(Examinee *exam[], int len){

    for (int i = 0; i< len; i ++){
        free(exam[i]);
    }
}
