/**
* pat1031
* Author: zhiying
* Date: 2021.2.27 21:35
*/
#include <stdio.h>
#include <stdlib.h>

#define N 19

int ctoi(char ch);
void free_mem(char *cards[], int len);
int is_digit(char ch);
int is_all_digit(char *card, int len);
int calculate_weight(char *card);
int check_code(char *card);

int main(){
    int n = 0;
    scanf("%d", &n);
    char *cards[n];

    for (int i = 0; i < n; i++){
        cards[i] = (char *)malloc(sizeof(char)* N);

        if(cards[i] != NULL){
            scanf("%s", cards[i]);
        }
    }

    int pass = 0;
    for (int j = 0; j < n; j++){

        if(is_all_digit(cards[j], 17)){

            if (check_code(cards[j])){
                pass++;
                continue;
            }
        }
        printf("%s\n",cards[j]);
    }

    if (pass == n){
        printf("All passed\n");
    }
    free_mem(cards, n);
    return 0;
}

int ctoi(char ch){
    // '0'的ASCII值为48
    return (int)ch - 48;
}

void free_mem(char *cards[], int len){

    for (int i = 0; i < len; i++){
        free(cards[i]);
    }
}

int is_digit(char ch){
    int flag = 0;
    if (ch >= '0' && ch <= '9'){
        flag = 1;
    }
    return flag;
}
int is_all_digit(char *card, int len){
    char *tmp = card;
    int cnt = 0;

    for (int i = 0; i < len; i ++){

        if (is_digit(*(tmp + i))){
            cnt ++;
        }
    }

    if (cnt == len){
        return 1;
    }else{
        return 0;
    }
}

int calculate_weight(char *card){
    char *tmp = card;
    int weights[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int weight = 0;

    for (int i = 0; i < N-2; i++){
        int num = ctoi(*(tmp + i));
        weight += num * weights[i];
    }

    return weight % 11;
}
int check_code(char *card){
    char code[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    int weight = calculate_weight(card);

    return code[weight] == *(card + 17) ? 1: 0;
}