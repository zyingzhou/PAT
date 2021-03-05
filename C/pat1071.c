/**
* 
* Author: zhiying
* Date: 2021/3/3
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>

//#define N 4;
void play_game(int *games[], int len, int total);
void free_mem(int *games[], int len);

int main(){
    int total = 0;
    int k = 0;
    scanf("%d %d", &total, &k);
    int *games[k];

    for (int i = 0; i < k; i++){
        games[i] = (int *)malloc(sizeof(int) * 4);

        if (games[i] != NULL){
            for (int j = 0; j < 4; j++){
                scanf("%d", (games[i] + j));
            }
        }

    }

    play_game(games, k, total);
    free_mem(games, k);
    return 0;
}

void play_game(int *games[], int len, int total){

    for (int i = 0; i < len; i++){

        if(total < *(games[i] + 2)){
            printf("Not enough tokens.  Total = %d.\n", total);
            continue;
        }

        if (*(games[i]) < *(games[i] + 3)){

            if (*(games[i] + 1) == 1){
                total += *(games[i] + 2);
                printf("Win %d!  Total = %d.\n", *(games[i] + 2), total);
                continue;
            }
        } else{

            if (*(games[i] + 1) == 0){
                total += *(games[i] + 2);
                printf("Win %d!  Total = %d.\n", *(games[i] + 2), total);
                continue;

            }
        }

        if (total >= *(games[i] + 2)){
            total -= *(games[i] + 2);;
            printf("Lose %d.  Total = %d.\n", *(games[i] + 2), total);
        }

        if (total == 0){
            printf("Game Over.\n");
            break;
        }


    }
}
void free_mem(int *games[], int len){

    for (int i = 0; i < len; i ++){
        free(games[i]);
    }

}